#include "Graphics/Graphics.h"
#include "SceneChoice.h"
#include "SceneGame.h"
#include "SceneManager.h"
#include "Input/Input.h"
#include "SceneLoading.h"

//初期化
void SceneChoice::Initialize()
{
    //スプライト初期化
    sprite = new Sprite("Data/Sprite/stageselect.png");
}

//終了化
void SceneChoice::Finalize()
{
    //スプライト終了化
    if (sprite != nullptr)
    {
        delete sprite;
        sprite = nullptr;
    }
}

//更新処理
void SceneChoice::Update(float elapsedTime)
{
    GamePad& gamePad = Input::Instance().GetGamePad();
    Stage& stage_ = Stage::Instance();

    //スペースキーを押したらゲームシーンへ切り替え
    const GamePadButton Button =
        GamePad::BTN_B
      | GamePad::BTN_X
      | GamePad::BTN_Y;
    if (gamePad.GetButton() & Button)
    {
        if (gamePad.GetButton() & GamePad::BTN_B)
        {
            stage_.Instance().Select(1);
        }
        if (gamePad.GetButton() & GamePad::BTN_X)
        {
            stage_.Instance().Select(2);
        }
        if (gamePad.GetButton() & GamePad::BTN_Y)
        {
            stage_.Instance().Select(3);
        }
        //SceneManager::Instance().ChangeScene(new SceneLoading(new SceneGame));
        SceneManager::Instance().ChangeScene(new SceneGame);
    }
}

//描画処理
void SceneChoice::Render()
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