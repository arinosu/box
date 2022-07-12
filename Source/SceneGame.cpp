#include "Graphics/Graphics.h"
#include "SceneGame.h"
#include "Camera.h"
#include "FloortileManager.h"
#include "Floortilebox.h"
#include "Input/Input.h"
#include "EffectManager.h"
#include "Scene.h"
#include "SceneClear.h"
#include "SceneManager.h"
#include "Stage.h"
#include "SceneLoading.h"
#include "BoxManager.h"

// ������
void SceneGame::Initialize()
{
	GamePad& gamePad = Input::Instance().GetGamePad();
	Stage& stage_ = Stage::Instance();

	//�X�e�[�W������
	stage = new Stage();

	//�I�[�f�B�I�����ݒ�
	bgm_1 = Audio::Instance().LoadAudioSource("Data/Audio/Stage1.wav");
	bgm_2 = Audio::Instance().LoadAudioSource("Data/Audio/Stage2.wav");
	bgm_3 = Audio::Instance().LoadAudioSource("Data/Audio/Stage3.wav");

	//�v���C���[������
	player = new Player();
	player->SetPosition(DirectX::XMFLOAT3(0.0f, 1.0f, 0.0f));

	//�X�v���C�g������
	sprite = new Sprite("Data/Sprite/gameover.png");

	//�^�C�}�[������
	timer = 0.0f;
	
	//�X�e�[�W1�̏�����
	if (stage_.number == 1) {
		floortilestage1 = new FloortileStage1();
		goal = new Goal();
		goal->SetPosition(DirectX::XMFLOAT3(0.0f, 1.0f, 500));
		floortilestage1->Initialize();
		bgm_1->Play(true);
	}

	//�X�e�[�W2�̏�����
	if (stage_.number == 2) {
		floortilestage2 = new FloortileStage2();
		goal = new Goal();
		goal->SetPosition(DirectX::XMFLOAT3(0.0f, -12.0f, 720));
		floortilestage2->Initialize();
		bgm_2->Play(true);
	}

	//�X�e�[�W3�̏�����
	if (stage_.number == 3) {
		floortilestage3 = new FloortileStage3();
		goal = new Goal();
		goal->SetPosition(DirectX::XMFLOAT3(0.0f, -7.0f, 840));
		floortilestage3->Initialize();
		bgm_3->Play(true);
	}

	//�J�����R���g���[���[������
	cameraController = new CameraController();

	//�J���������ݒ�
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

// �I����
void SceneGame::Finalize()
{
	if (goal != nullptr)
	{
		delete goal;
		goal = nullptr;
	}

	//�v���C���[�I����
	if (player != nullptr)
	{
		delete player;
		player = nullptr;
	}

	// �X�v���C�g�I����
	if (sprite != nullptr)
	{
		delete sprite;
		sprite = nullptr;
	}

	//���̏I����
	FloorTileManager::Instance().Clear();

	//��Q���̏I����
	BoxManager::Instance().Clear();

	//�J�����R���g���[���[�I����
	if (cameraController != nullptr)
	{
		delete cameraController;
		cameraController = nullptr;
	}

	//�X�e�[�W�I����
	if (stage != nullptr)
	{
		delete stage;
		stage = nullptr;
	}

	//�X�e�[�W1�̏I����
	if (floortilestage1 != nullptr)
	{
		bgm_1->Stop();
		bgm_1->~AudioSource();
		delete floortilestage1;
		floortilestage1 = nullptr;
	}

	//�X�e�[�W2�̏I����
	if (floortilestage2 != nullptr)
	{
		bgm_2->Stop();
		bgm_2->~AudioSource();
		delete floortilestage2;
		floortilestage2 = nullptr;
	}

	//�X�e�[�W3�̏I����
	if (floortilestage3 != nullptr)
	{
		bgm_3->Stop();
		bgm_3->~AudioSource();
		delete floortilestage3;
		floortilestage3 = nullptr;
	}

}

// �X�V����
void SceneGame::Update(float elapsedTime)
{
	GamePad& gamePad = Input::Instance().GetGamePad();

	//�J�����R���g���[���[�X�V����
	DirectX::XMFLOAT3 target = player->GetPosition();
	target.y += 3.5f;
	float cameraSpeed = 2.0f * elapsedTime;
	cameraController->SetTarget(target);
	cameraController->SetSpeed(cameraSpeed);
	cameraController->Update(elapsedTime);
	
	//�X�e�[�W�X�V����
	stage->Update(elapsedTime);

	//�v���C���[�X�V����
	player->Update(elapsedTime);

	//�S�[���X�V����
	goal->Update(elapsedTime);

	//���X�V����
	FloorTileManager::Instance().Update(elapsedTime);

	//��Q���X�V����
	BoxManager::Instance().Update(elapsedTime);

	//�G�t�F�N�g�X�V����
	EffectManager::Instance().Update(elapsedTime);


	if (player->GetLife() == false && player->GetPosition().z < goal->GetPosition().z)
	{
		timer++;
		//�X�y�[�X�L�[����������Z���N�g��ʂ֐؂�ւ�
			Finalize();
			SceneManager::Instance().ChangeScene(new SceneLoading(new SceneGame));
	}
	else
	{
		if (player->GetPosition().z >= goal->GetPosition().z && player->GetLife())
		{
			SceneManager::Instance().ChangeScene(new SceneClear);
		}
	}
}

// �`�揈��
void SceneGame::Render()
{
	Graphics& graphics = Graphics::Instance();
	ID3D11DeviceContext* dc = graphics.GetDeviceContext();
	ID3D11RenderTargetView* rtv = graphics.GetRenderTargetView();
	ID3D11DepthStencilView* dsv = graphics.GetDepthStencilView();

	// ��ʃN���A�������_�[�^�[�Q�b�g�ݒ�
	FLOAT color[] = { 0.0f, 0.0f, 0.5f, 1.0f };	// RGBA(0.0�`1.0)
	dc->ClearRenderTargetView(rtv, color);
	dc->ClearDepthStencilView(dsv, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);
	dc->OMSetRenderTargets(1, &rtv, dsv);

	// �`�揈��
	RenderContext rc;
	rc.lightDirection = { 0.0f, -1.0f, 0.0f, 0.0f };	// ���C�g�����i�������j

	//�J�����p�����[�^�ݒ�
	Camera& camera = Camera::Instance();
	rc.view = camera.GetView();
	rc.projection = camera.GetProjection();

	// 3D���f���`��
	{
		Shader* shader = graphics.GetShader();
		shader->Begin(dc, rc);

		//�X�e�[�W�`��
		stage->Render(dc, shader);

		//�v���C���[�`��
		player->Render(dc, shader);

		// �S�[���`��
		goal->Render(dc, shader);

		//���`��
		FloorTileManager::Instance().Render(dc, shader);

		//��Q���`��
		BoxManager::Instance().Render(dc, shader);

		//�����艺�ɏ����ƕ`�悳��Ȃ�
		shader->End(dc);
	}

	//3D�G�t�F�N�g�`��
	{
		EffectManager::Instance().Render(rc.view, rc.projection);
	}

	// 3D�f�o�b�O�`��
	{
		//�v���C���[�f�o�b�O�v���~�e�B�u�`��
		player->DrawDebugPrimitive();

		//��	�f�o�b�O�v���~�e�B�u�`��
		FloorTileManager::Instance().DrawDebugPrimitive();

		//��Q���f�o�b�O�v���~�e�B�u�`��
		BoxManager::Instance().DrawDebugPrimitive();

		// ���C�������_���`����s
		graphics.GetLineRenderer()->Render(dc, rc.view, rc.projection);

		// �f�o�b�O�����_���`����s
		graphics.GetDebugRenderer()->Render(dc, rc.view, rc.projection);
	}

	// 2D�X�v���C�g�`��
	{
		float screenWidth = static_cast<float>(graphics.GetScreenWidth());
		float screenHeight = static_cast<float>(graphics.GetScreenHeight());
		float textureWidth = static_cast<float>(sprite->GetTextureWidth());
		float textureHeight = static_cast<float>(sprite->GetTextureHeight());
	}

	// 2D�f�o�b�OGUI�`��
	{
		//�v���C���[�f�o�b�O�`��
		player->DrawDebugGUI();
	}
}
