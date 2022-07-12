#pragma once

#include "Graphics/Sprite.h"
#include "Scene.h"
#include <thread>

// ローディングシーン
class SceneLoading : public Scene
{
public:
	SceneLoading(Scene* nextScene) : nextScene(nextScene) {}

	SceneLoading() {}
	~SceneLoading() override {}

	// 初期化
	virtual void Initialize() override;

	// 終了化
	virtual void Finalize() override;

	// 更新処理
	virtual void Update(float elapsedTime) override;

	// 描画処理
	virtual void Render() override;

private:
	// ローディングスレッド
	static void LoadingThread(SceneLoading* scene);

private:
	Sprite* sprite = nullptr;
	float angle = 0.0f;
	Scene* nextScene = nullptr;
	std::thread* thread = nullptr;
};