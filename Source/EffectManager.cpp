#include "Graphics/Graphics.h"
#include "EffectManager.h"

//������
void EffectManager::Initialize()
{
    Graphics& graphics = Graphics::Instance();

    //Effekseer�����_������
    effekseerRender = EffekseerRendererDX11::Renderer::Create(graphics.GetDevice(), graphics.GetDeviceContext(), 2048);

    //Effekseer�}�l�[�W���[����
    effekseerManager = Effekseer::Manager::Create(2048);

    //Effekseer�����_���̊e��ݒ�i���ʂȃJ�X�^�}�C�Y�����Ȃ��ꍇ�͒�^�I�Ɉȉ��̐ݒ��OK�j
    effekseerManager->SetSpriteRenderer(effekseerRender->CreateSpriteRenderer());
    effekseerManager->SetRibbonRenderer(effekseerRender->CreateRibbonRenderer());
    effekseerManager->SetRingRenderer(effekseerRender->CreateRingRenderer());
    effekseerManager->SetTrackRenderer(effekseerRender->CreateTrackRenderer());
    effekseerManager->SetModelRenderer(effekseerRender->CreateModelRenderer());
    //Effekseer���ł̃��[�_�[�̐ݒ�i���ʂȃJ�X�^�}�C�Y�����Ȃ��ꍇ�͈ȉ��̐ݒ��OK�j
    effekseerManager->SetTextureLoader(effekseerRender->CreateTextureLoader());
    effekseerManager->SetModelLoader(effekseerRender->CreateModelLoader());
    effekseerManager->SetMaterialLoader(effekseerRender->CreateMaterialLoader());

    //Effekseer��������W�n�Ōv�Z����
    effekseerManager->SetCoordinateSystem(Effekseer::CoordinateSystem::LH);
}

//�I����
void EffectManager::Finalize()
{
    //EffekseerManager�Ȃǂ̓X�}�[�g�|�C���^�ɂ���Ĕj�������̂ŉ������Ȃ�
}

//�X�V����
void EffectManager::Update(float elapsedTime)
{
    //�G�t�F�N�g�X�V�����i�����ɂ̓t���[���̌o�ߎ��Ԃ�n���j
    effekseerManager->Update(elapsedTime * 60.0f);
}

//�`�揈��
void EffectManager::Render(const DirectX::XMFLOAT4X4& view, const DirectX::XMFLOAT4X4& projection)
{
    //�r���[���v���W�F�N�V�����s���Effekseer�����_���ɐݒ�
    effekseerRender->SetCameraMatrix(*reinterpret_cast<const Effekseer::Matrix44*>(&view));
    effekseerRender->SetProjectionMatrix(*reinterpret_cast<const Effekseer::Matrix44*>(&projection));

    //Effekseer�`��J�n
    effekseerRender->BeginRendering();

    //Effekseer�`����s
    //�}�l�[�W���[�P�ʂŕ`�悷��̂ŕ`�揇�𐧌䂷��ꍇ�̓}�l�[�W���[�𕡐��쐬���A
    //Draw()�֐������s���鏇���Ő���ł�����
    effekseerManager->Draw();

    //Effekseer�`��I��
    effekseerRender->EndRendering();
}
