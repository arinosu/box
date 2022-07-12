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

// ゲームシーン
class SceneGame :public Scene
{
public:
	SceneGame() {}
	~SceneGame() override {}


	// 初期化
	void Initialize()override;

	// 終了化
	void Finalize()override;

	// 更新処理
	void Update(float elapsedTime)override;

	// 描画処理
	void Render()override;

private:
	Stage* stage = nullptr;   //例外スローを解消するため
	Player* player = nullptr; //例外スローを解消するため
	FloorTile* floorTile = nullptr; //例外スローを解消するため
	Goal* goal = nullptr;//例外スローを解消するため
	CameraController* cameraController = nullptr;//例外スローを解消するため
	FloortileStage1* floortilestage1 = nullptr;//例外スローを解消するため
	FloortileStage2* floortilestage2 = nullptr;//例外スローを解消するため
	FloortileStage3* floortilestage3 = nullptr;//例外スローを解消するため
	float timer = 0;
	Sprite* sprite = nullptr;

	std::unique_ptr<AudioSource> bgm_1;
	std::unique_ptr<AudioSource> bgm_2;
	std::unique_ptr<AudioSource> bgm_3;
};
