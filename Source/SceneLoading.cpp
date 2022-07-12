#include "Graphics/Graphics.h"
#include "Input/Input.h"
#include "SceneLoading.h"
#include "SceneManager.h"

//初期化
void SceneLoading::Initialize()
{
    //モデル初期化
    model = new Model("Data/Model/Car/car.mdl");

    //モデルが大きいのでスケーリング、あまりしないほうが良い
    scale.x = scale.y = scale.z = 0.25f;

    //スプライト初期化
    sprite = new Sprite("Data/Sprite/LoadingIcon.png");

    //スレッド開始
    thread = new std::thread(LoadingThread, this);
}

//終了化
void SceneLoading::Finalize()
{
    //スレッド終了化
    if (thread != nullptr)
    {
        thread->join();
        delete thread;
        thread = nullptr;
    }

    //モデルを破棄
    delete model;

    //スプライト終了化
    if (sprite != nullptr)
    {
        delete sprite;
        sprite = nullptr;
    }
}

//更新処理
void SceneLoading::Update(float elapsedTime)
{
    //オブジェクト行列を更新
    UpdateTransform();

    //モデル行列更新
    model->UpdateTransform(transform);

    constexpr float speed = 180;
    angle += speed * elapsedTime;

    //次のシーンの準備が完了したらシーンを切り替える
    if (nextScene->IsReady())
    {
        SceneManager::Instance().ChangeScene(nextScene);
        nextScene = nullptr;
    }
}

void SceneLoading::RENDER(ID3D11DeviceContext* dc, Shader* shader)
{
    shader->Draw(dc, model);
}

//描画処理
void SceneLoading::Render()
{
    Graphics& graphics = Graphics::Instance();
    ID3D11DeviceContext* dc = graphics.GetDeviceContext();
    ID3D11RenderTargetView* rtv = graphics.GetRenderTargetView();
    ID3D11DepthStencilView* dsv = graphics.GetDepthStencilView();

    //画面クリア＆レンダーターゲット設定
    FLOAT color[] = { 0.0f,0.0f,0.5f,1.0f };   //RGBA(0.0~1.0)
    dc->ClearRenderTargetView(rtv, color);
    dc->ClearDepthStencilView(dsv, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);
    dc->OMSetRenderTargets(1, &rtv, dsv);

    //2Dスプライト描画
    {
        //画面右下にローディングアイコンを描画
        float screenWidth = static_cast<float>(graphics.GetScreenWidth());
        float screenHeight = static_cast<float>(graphics.GetScreenHeight());
        float textureWidth = static_cast<float>(sprite->GetTextureWidth());
        float textureHeight = static_cast<float>(sprite->GetTextureHeight());
        float positionX = screenWidth - textureWidth;
        float positionY = screenHeight - textureHeight;
        //タイトルスプライト描画
        sprite->Render(dc, positionX, positionY, textureWidth, textureHeight, 0, 0, textureWidth, textureHeight, angle, 1, 1, 1, 1);
    }
}

//ローディングスレッド
void SceneLoading::LoadingThread(SceneLoading* scene)
{
    //COM関連の初期化でスレッド毎に呼ぶ必要がある
    HRESULT hr = CoInitialize(nullptr);

    //次のシーンの初期化を行う
    scene->nextScene->Initialize();

    //スレッドが終わる前にCOM関連の終了化
    CoUninitialize();

    //次のシーンの準備完了設定
    scene->nextScene->SetReady();
}

void SceneLoading::UpdateTransform()
{
    //スケール行列を更新
    DirectX::XMMATRIX S = DirectX::XMMatrixScaling(scale.x, scale.y, scale.z);

    //回転行列を作成
    DirectX::XMMATRIX R = DirectX::XMMatrixRotationRollPitchYaw(angl.x, angl.y, angl.z);

    //位置行列を作成
    DirectX::XMMATRIX T = DirectX::XMMatrixTranslation(position.x, position.y, position.z);

    //３つの行列を組み合わせ、ワールド行列を作成
    DirectX::XMMATRIX W = S * R * T;

    //計算したワールド行列を取り出す
    DirectX::XMStoreFloat4x4(&transform, W);
}
