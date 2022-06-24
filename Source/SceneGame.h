#pragma once

#include "Stage.h"
#include "Player.h"
#include "floortile.h"
#include "CameraController.h"

// ゲームシーン
class SceneGame
{
public:
	SceneGame() {}
	~SceneGame() {}

	// 初期化
	void Initialize();

	// 終了化
	void Finalize();

	// 更新処理
	void Update(float elapsedTime);

	// 描画処理
	void Render();

private:
	Stage* stage = nullptr;   //例外スローを解消するため
	Player* player = nullptr; //例外スローを解消するため
	FloorTile* floorTile = nullptr; //例外スローを解消するため
	CameraController* cameraController = nullptr;//例外スローを解消するため
};
