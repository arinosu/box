#include "Graphics/Graphics.h"
#include "Input/Input.h"
#include "SceneLoading.h"
#include "SceneManager.h"

//������
void SceneLoading::Initialize()
{
    //���f��������
    model = new Model("Data/Model/Car/car.mdl");

    //���f�����傫���̂ŃX�P�[�����O�A���܂肵�Ȃ��ق����ǂ�
    scale.x = scale.y = scale.z = 0.25f;

    //�X�v���C�g������
    sprite = new Sprite("Data/Sprite/LoadingIcon.png");

    //�X���b�h�J�n
    thread = new std::thread(LoadingThread, this);
}

//�I����
void SceneLoading::Finalize()
{
    //�X���b�h�I����
    if (thread != nullptr)
    {
        thread->join();
        delete thread;
        thread = nullptr;
    }

    //���f����j��
    delete model;

    //�X�v���C�g�I����
    if (sprite != nullptr)
    {
        delete sprite;
        sprite = nullptr;
    }
}

//�X�V����
void SceneLoading::Update(float elapsedTime)
{
    //�I�u�W�F�N�g�s����X�V
    UpdateTransform();

    //���f���s��X�V
    model->UpdateTransform(transform);

    constexpr float speed = 180;
    angle += speed * elapsedTime;

    //���̃V�[���̏���������������V�[����؂�ւ���
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

//�`�揈��
void SceneLoading::Render()
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
        //��ʉE���Ƀ��[�f�B���O�A�C�R����`��
        float screenWidth = static_cast<float>(graphics.GetScreenWidth());
        float screenHeight = static_cast<float>(graphics.GetScreenHeight());
        float textureWidth = static_cast<float>(sprite->GetTextureWidth());
        float textureHeight = static_cast<float>(sprite->GetTextureHeight());
        float positionX = screenWidth - textureWidth;
        float positionY = screenHeight - textureHeight;
        //�^�C�g���X�v���C�g�`��
        sprite->Render(dc, positionX, positionY, textureWidth, textureHeight, 0, 0, textureWidth, textureHeight, angle, 1, 1, 1, 1);
    }
}

//���[�f�B���O�X���b�h
void SceneLoading::LoadingThread(SceneLoading* scene)
{
    //COM�֘A�̏������ŃX���b�h���ɌĂԕK�v������
    HRESULT hr = CoInitialize(nullptr);

    //���̃V�[���̏��������s��
    scene->nextScene->Initialize();

    //�X���b�h���I���O��COM�֘A�̏I����
    CoUninitialize();

    //���̃V�[���̏��������ݒ�
    scene->nextScene->SetReady();
}

void SceneLoading::UpdateTransform()
{
    //�X�P�[���s����X�V
    DirectX::XMMATRIX S = DirectX::XMMatrixScaling(scale.x, scale.y, scale.z);

    //��]�s����쐬
    DirectX::XMMATRIX R = DirectX::XMMatrixRotationRollPitchYaw(angl.x, angl.y, angl.z);

    //�ʒu�s����쐬
    DirectX::XMMATRIX T = DirectX::XMMatrixTranslation(position.x, position.y, position.z);

    //�R�̍s���g�ݍ��킹�A���[���h�s����쐬
    DirectX::XMMATRIX W = S * R * T;

    //�v�Z�������[���h�s������o��
    DirectX::XMStoreFloat4x4(&transform, W);
}
