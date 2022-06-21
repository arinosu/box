#pragma once

#include "Stage.h"
#include "Player.h"
#include "floortile.h"

// �Q�[���V�[��
class SceneGame
{
public:
	SceneGame() {}
	~SceneGame() {}

	// ������
	void Initialize();

	// �I����
	void Finalize();

	// �X�V����
	void Update(float elapsedTime);

	// �`�揈��
	void Render();

private:
	Stage* stage = nullptr;   //��O�X���[���������邽��
	Player* player = nullptr; //��O�X���[���������邽��
	FloorTile* floorTile = nullptr; //��O�X���[���������邽��
};
