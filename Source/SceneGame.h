#pragma once

#include "Stage.h"
#include "Player.h"
#include "floortile.h"
#include "Goal.h"
#include "CameraController.h"
#include "FloortileStage1.h"
#include "FloortileStage2.h"
#include "FloortileStage3.h"
#include "Scene.h"
#include "Graphics/Sprite.h"
#include "Audio/Audio.h"

// �Q�[���V�[��
class SceneGame :public Scene
{
public:
	SceneGame() {}
	~SceneGame() override {}


	// ������
	void Initialize()override;

	// �I����
	void Finalize()override;

	// �X�V����
	void Update(float elapsedTime)override;

	// �`�揈��
	void Render()override;

private:
	Stage* stage = nullptr;   //��O�X���[���������邽��
	Player* player = nullptr; //��O�X���[���������邽��
	FloorTile* floorTile = nullptr; //��O�X���[���������邽��
	Goal* goal = nullptr;//��O�X���[���������邽��
	CameraController* cameraController = nullptr;//��O�X���[���������邽��
	FloortileStage1* floortilestage1 = nullptr;//��O�X���[���������邽��
	FloortileStage2* floortilestage2 = nullptr;//��O�X���[���������邽��
	FloortileStage3* floortilestage3 = nullptr;//��O�X���[���������邽��
	float timer = 0;
	Sprite* sprite = nullptr;

	std::unique_ptr<AudioSource> bgm_1;
	std::unique_ptr<AudioSource> bgm_2;
	std::unique_ptr<AudioSource> bgm_3;
};
