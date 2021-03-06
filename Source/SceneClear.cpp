#include "Graphics/Graphics.h"
#include "SceneClear.h"
#include "Input/Input.h"
#include "SceneTitle.h"
#include "SceneChoice.h"
#include "SceneManager.h"

//初期化
void SceneClear::Initialize()
{
    //スプライト初期化
    sprite = new Sprite("Data/Sprite/stageclear.png");
}

//終了化
void SceneClear::Finalize()
{
    //スプライト終了化
    if (sprite != nullptr)
    {
        delete sprite;
        sprite = nullptr;
    }
}

//更新処理
void SceneClear::Update(float elapsedTime)
{
    GamePad& gamePad = Input::Instance().GetGamePad();

    const GamePadButton anyButton =
        GamePad::BTN_A |
        GamePad::BTN_BACK;

    if (gamePad.GetButtonDown() & anyButton)
    {
        if (gamePad.GetButton() & GamePad::BTN_A) // Space
        {
            SceneManager::Instance().ChangeScene(new SceneChoice);
        }
        if (gamePad.GetButton() & GamePad::BTN_BACK) // BACKSPACE
        {
            SceneManager::Instance().ChangeScene(new SceneTitle);
        }
    }
}

//描画処理
void SceneClear::Render()
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
        float screenWidth = static_cast<float>(graphics.GetScreenWidth());
        float screenHeight = static_cast<float>(graphics.GetScreenHeight());
        float textureWidth = static_cast<float>(sprite->GetTextureWidth());
        float textureHeight = static_cast<float>(sprite->GetTextureHeight());
        //タイトルスプライト描画
        sprite->Render(dc, 0, 0, screenWidth, screenHeight, 0, 0, textureWidth, textureHeight, 0, 1, 1, 1, 1);
    }
}