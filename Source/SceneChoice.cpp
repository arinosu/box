#include "Graphics/Graphics.h"
#include "SceneChoice.h"
#include "SceneGame.h"
#include "SceneManager.h"
#include "Input/Input.h"

//������
void SceneChoice::Initialize()
{
    //�X�v���C�g������
    sprite = new Sprite("Data/Sprite/stageselect.png");
}

//�I����
void SceneChoice::Finalize()
{
    //�X�v���C�g�I����
    if (sprite != nullptr)
    {
        delete sprite;
        sprite = nullptr;
    }
}

//�X�V����
void SceneChoice::Update(float elapsedTime)
{
    GamePad& gamePad = Input::Instance().GetGamePad();

    //�X�y�[�X�L�[����������Q�[���V�[���֐؂�ւ�
    const GamePadButton Button =
        GamePad::BTN_B
      | GamePad::BTN_X
      | GamePad::BTN_Y;
    if (gamePad.GetButton() & Button)
    {
        SceneManager::Instance().ChangeScene(new SceneGame);
    }
}

//�`�揈��
void SceneChoice::Render()
{
    Graphics& graphics = Graphics::Instance();
    ID3D11DeviceContext* dc = graphics.GetDeviceContext();
    ID3D11RenderTargetView* rtv = graphics.GetRenderTargetView();
    ID3D11DepthStencilView* dsv = graphics.GetDepthStencilView();

    //��ʃN���A�������_�[�^�[�Q�b�g�ݒ�
    FLOAT color[] = { 0.0f,0.0f,0.5f,1.0f };   //RGBA(0.0~1.0)
    dc->ClearRenderTargetView(rtv, color);
    dc->ClearDepthStencilView(dsv, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);
    dc->OMSetRenderTargets(1, &rtv, dsv);

    //2D�X�v���C�g�`��
    {
        float screenWidth = static_cast<float>(graphics.GetScreenWidth());
        float screenHeight = static_cast<float>(graphics.GetScreenHeight());
        float textureWidth = static_cast<float>(sprite->GetTextureWidth());
        float textureHeight = static_cast<float>(sprite->GetTextureHeight());
        //�^�C�g���X�v���C�g�`��
        sprite->Render(dc, 0, 0, screenWidth, screenHeight, 0, 0, textureWidth, textureHeight, 0, 1, 1, 1, 1);
    }
}