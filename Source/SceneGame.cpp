#include "Graphics/Graphics.h"
#include "SceneGame.h"
#include "Camera.h"
#include "FloortileManager.h"
#include "BoxManager.h"
#include "Floortilebox.h"
#include "Input/Input.h"
#include "EffectManager.h"
#include "Scene.h"
#include "SceneOver.h"
#include "SceneManager.h"

// 初期化
void SceneGame::Initialize()
{
	GamePad& gamePad = Input::Instance().GetGamePad();

	//ステージ初期化
	stage = new Stage();

	//スプライト初期化、ゲームオーバー画面
	sprite = new Sprite("Data/Sprite/gameover.png");

	//タイマー初期化
	timer = 0.0f;

	//プレイヤー初期化
	player = new Player();
	player->SetPosition(DirectX::XMFLOAT3(0.0f, 1.0f, -1.6f));

	//ステージ1の初期化
	if (gamePad.GetButton() & GamePad::BTN_B) {
		floortilestage1 = new FloortileStage1();
		goal = new Goal();
		goal->SetPosition(DirectX::XMFLOAT3(0.0f, 1.0f, 500));
		floortilestage1->Initialize();
	}

	//ステージ2の初期化
	if (gamePad.GetButton() & GamePad::BTN_X) {
		floortilestage2 = new FloortileStage2();
		floortilestage2->Initialize();
	}

	//ステージ3の初期化
	if (gamePad.GetButton() & GamePad::BTN_Y) {
		floortilestage3 = new FloortileStage3();
		floortilestage3->Initialize();
	}

	//カメラコントローラー初期化
	cameraController = new CameraController();

	//カメラ初期設定
	Graphics& graphics = Graphics::Instance();
	Camera& camera = Camera::Instance();
	camera.SetLookAt(
		DirectX::XMFLOAT3(0, 0, 0),
		DirectX::XMFLOAT3(0, 1, 0),
		DirectX::XMFLOAT3(0, 1, 0)
	);
	camera.SetPerspectiveFov(
		DirectX::XMConvertToRadians(80),
		graphics.GetScreenWidth() / graphics.GetScreenHeight(),
		0.1f,
		1000.0f
	);
}

// 終了化
void SceneGame::Finalize()
{
	//ステージ終了化
	if (stage != nullptr)
	{
		delete stage;
		stage = nullptr;
	}

	// スプライト終了化
	if (sprite != nullptr)
	{
		delete sprite;
		sprite = nullptr;
	}

	//プレイヤー終了化
	if (player != nullptr)
	{
		delete player;
		player = nullptr;
	}

	//箱の終了化
	FloorTileManager::Instance().Clear();

	//障害物の終了化
	BoxManager::Instance().Clear();

	//ゴールの終了化
	if (goal != nullptr)
	{
		delete goal;
		goal = nullptr;
	}

	//ステージ1の終了化
	if (floortilestage1 != nullptr)
	{
		delete floortilestage1;
		floortilestage1 = nullptr;
	}

	//ステージ2の終了化
	if (floortilestage2 != nullptr)
	{
		delete floortilestage2;
		floortilestage2 = nullptr;
	}

	//ステージ3の終了化
	if (floortilestage3 != nullptr)
	{
		delete floortilestage3;
		floortilestage3 = nullptr;
	}

	//カメラコントローラー終了化
	if (cameraController != nullptr)
	{
		delete cameraController;
		cameraController = nullptr;
	}
}

// 更新処理
void SceneGame::Update(float elapsedTime)
{
	GamePad& gamePad = Input::Instance().GetGamePad();

	//ステージ更新処理
	stage->Update(elapsedTime);

	//プレイヤー更新処理
	player->Update(elapsedTime);

	//箱更新処理
	FloorTileManager::Instance().Update(elapsedTime);

	//障害物更新処理
	BoxManager::Instance().Update(elapsedTime);

	//ゴールの更新処理
	goal->Update(elapsedTime);

	//カメラコントローラー更新処理
	DirectX::XMFLOAT3 target = player->GetPosition();
	target.y += 3.5f;
	float cameraSpeed = 9.5f * elapsedTime;
	cameraController->SetTarget(target);
	cameraController->Update(elapsedTime);

	//エフェクト更新処理
	EffectManager::Instance().Update(elapsedTime);

	//プレイヤーが死亡処理
	if (player->GetLife() == false)
	{
		timer++;
		//スペースキーを押したらセレクト画面へ切り替え
		const GamePadButton Button =
			GamePad::BTN_A;
		if (gamePad.GetButton() & Button)
		{
			//初期化する
			Initialize();
		}
	}
}

// 描画処理
void SceneGame::Render()
{
	Graphics& graphics = Graphics::Instance();
	ID3D11DeviceContext* dc = graphics.GetDeviceContext();
	ID3D11RenderTargetView* rtv = graphics.GetRenderTargetView();
	ID3D11DepthStencilView* dsv = graphics.GetDepthStencilView();

	// 画面クリア＆レンダーターゲット設定
	FLOAT color[] = { 0.0f, 0.0f, 0.5f, 1.0f };	// RGBA(0.0～1.0)
	dc->ClearRenderTargetView(rtv, color);
	dc->ClearDepthStencilView(dsv, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);
	dc->OMSetRenderTargets(1, &rtv, dsv);

	// 描画処理
	RenderContext rc;
	rc.lightDirection = { 0.0f, -1.0f, 0.0f, 0.0f };	// ライト方向（下方向）

	//カメラパラメータ設定
	Camera& camera = Camera::Instance();
	rc.view = camera.GetView();
	rc.projection = camera.GetProjection();

	// 3Dモデル描画
	{
		Shader* shader = graphics.GetShader();
		shader->Begin(dc, rc);
		//ステージ描画
		stage->Render(dc, shader);

		//プレイヤー描画
		player->Render(dc, shader);

		//箱描画
		FloorTileManager::Instance().Render(dc, shader);

		//障害物描画
		BoxManager::Instance().Render(dc, shader);

		//ゴールの描画
		goal->Render(dc, shader);

		//これより下に書くと描画されない
		shader->End(dc);
	}

	//3Dエフェクト描画
	{
		EffectManager::Instance().Render(rc.view, rc.projection);
	}

	// 3Dデバッグ描画
	{
		//プレイヤーデバッグプリミティブ描画
		player->DrawDebugPrimitive();

		//箱	デバッグプリミティブ描画
		FloorTileManager::Instance().DrawDebugPrimitive();

		//障害物デバッグプリミティブ描画
		BoxManager::Instance().DrawDebugPrimitive();

		// ラインレンダラ描画実行
		graphics.GetLineRenderer()->Render(dc, rc.view, rc.projection);

		// デバッグレンダラ描画実行
		graphics.GetDebugRenderer()->Render(dc, rc.view, rc.projection);
	}

	// 2Dスプライト描画
	{
		float screenWidth = static_cast<float>(graphics.GetScreenWidth());
		float screenHeight = static_cast<float>(graphics.GetScreenHeight());
		float textureWidth = static_cast<float>(sprite->GetTextureWidth());
		float textureHeight = static_cast<float>(sprite->GetTextureHeight());
		if (player->GetLife() == false)
		{
			sprite->Render(dc, 0, 0, screenWidth, screenHeight, 0, 0, textureWidth, textureHeight, 0, 1, 1, 1, 1);
		}
	}

	// 2DデバッグGUI描画
	{
		//プレイヤーデバッグ描画
		player->DrawDebugGUI();
	}
}