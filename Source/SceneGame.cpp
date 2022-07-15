#include "Graphics/Graphics.h"
#include "SceneGame.h"
#include "Camera.h"
#include "FloortileManager.h"
#include "BoxManager.h"
#include "Floortilebox.h"
#include "Input/Input.h"
#include "EffectManager.h"
#include "Scene.h"
#include "SceneManager.h"
#include "SceneClear.h"
#include "SceneLoading.h"

// 初期化
void SceneGame::Initialize()
{
	GamePad& gamePad = Input::Instance().GetGamePad();
	Stage& stage_ = Stage::Instance();

	//背景初期
	sprite = new Sprite("Data/Sprite/space.png");

	//ステージ初期化
	stage = new Stage();
	stage->SetPosition(DirectX::XMFLOAT3(165.0f, 100.0f, 0.0f));

	//音楽初期設定
	stagebgm[0] = Audio::Instance().LoadAudioSource("Data/Audio/Stage1.wav");
	stagebgm[1] = Audio::Instance().LoadAudioSource("Data/Audio/Stage2.wav");
	stagebgm[2] = Audio::Instance().LoadAudioSource("Data/Audio/Stage3.wav");

	//プレイヤー初期化
	player = new Player();
	player->SetPosition(DirectX::XMFLOAT3(0.0f, 1.0f, -1.6f));

	//ステージ1の初期化
	if (stage_.number==1) {
		floortilestage1 = new FloortileStage1();

		//ゴール初期化
		goal = new Goal();
		goal->SetPosition(DirectX::XMFLOAT3(0.0f, 2.0f, 500));
		floortilestage1->Initialize();

		//音楽プレイ
		stagebgm[0]->Play(true);
	}

	//ステージ2の初期化
	if (stage_.number == 2) {
		floortilestage2 = new FloortileStage2();

		//ゴール初期化
		goal = new Goal();
		goal->SetPosition(DirectX::XMFLOAT3(0.0f, -12.0f, 720));
		floortilestage2->Initialize();

		//音楽プレイ
		stagebgm[1]->Play(true);
	}

	//ステージ3の初期化
	if (stage_.number == 3) {
		floortilestage3 = new FloortileStage3();

		//ゴール初期化
		goal = new Goal();
		goal->SetPosition(DirectX::XMFLOAT3(0.0f, -7.0f, 840));
		floortilestage3->Initialize();

		//音楽プレイ
		stagebgm[2]->Play(true);
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
	//背景終了化
	delete sprite;

	//ゴールの終了化
	if (goal != nullptr)
	{
		delete goal;
		goal = nullptr;
	}

	//ステージ終了化
	if (stage != nullptr)
	{
		delete stage;
		stage = nullptr;
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

	//ステージ1の終了化
	if (floortilestage1 != nullptr)
	{
		stagebgm[0]->Stop();
		stagebgm[0]->~AudioSource();
		delete floortilestage1;
		floortilestage1 = nullptr;
	}

	//ステージ2の終了化
	if (floortilestage2 != nullptr)
	{
		stagebgm[1]->Stop();
		stagebgm[1]->~AudioSource();
		delete floortilestage2;
		floortilestage2 = nullptr;
	}

	//ステージ3の終了化
	if (floortilestage3 != nullptr)
	{
		stagebgm[2]->Stop();
		stagebgm[2]->~AudioSource();
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

	//カメラコントローラー更新処理
	DirectX::XMFLOAT3 target = player->GetPosition();
	target.y += 3.5f;
	float cameraSpeed = 9.5f * elapsedTime;
	cameraController->SetTarget(target);
	cameraController->Update(elapsedTime);

	//ステージ更新処理
	stage->Update(elapsedTime);
	 
	//プレイヤー更新処理
	player->Update(elapsedTime);

	//ゴールの更新処理
	goal->Update(elapsedTime);

	//箱更新処理
	FloorTileManager::Instance().Update(elapsedTime);

	//障害物更新処理
	BoxManager::Instance().Update(elapsedTime);

	//エフェクト更新処理
	EffectManager::Instance().Update(elapsedTime);

	//死亡処理
	if (player->GetLife() == false && player->GetPosition().z < goal->GetPosition().z)
	{
		//スペースキーを押したらセレクト画面へ切り替え
		SceneManager::Instance().ChangeScene(new SceneLoading(new SceneGame));
	}
	//STAGECLEAR処理
	else
	{
		if (player->GetPosition().z >= goal->GetPosition().z && player->GetLife())
		{
			timer++;
			//ゴールしたらクリア
			if (timer >= 300) {
				SceneManager::Instance().ChangeScene(new SceneClear);
			}
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
	FLOAT color[] = { 1.0f, 0.0f, 0.5f, 1.0f };	// RGBA(0.0～1.0)
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

	// 2Dスプライト描画
	{
		float screenWidth = static_cast<float>(graphics.GetScreenWidth());
		float screenHeight = static_cast<float>(graphics.GetScreenHeight());
		float textureWidth = static_cast<float>(sprite->GetTextureWidth());
		float textureHeight = static_cast<float>(sprite->GetTextureHeight());
		//タイトルスプライト描画
		sprite->Render(dc, 0, 0, screenWidth, screenHeight, 0, 0, textureWidth, textureHeight, 0, 1, 1, 1, 1);
	}

	// 3Dモデル描画
	{
		Shader* shader = graphics.GetShader();
		shader->Begin(dc, rc);
		//ステージ描画
		stage->Render(dc, shader);

		//プレイヤー描画
		player->Render(dc, shader);

		//ゴールの描画
		goal->Render(dc, shader);

		//箱描画
		FloorTileManager::Instance().Render(dc, shader);

		//障害物描画
		BoxManager::Instance().Render(dc, shader);

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

	// 2DデバッグGUI描画
	{
		//プレイヤーデバッグ描画
		player->DrawDebugGUI();
	}
}