#include "SceneManager.h"

//更新処理
void SceneManager::Update(float elapsedTime)
{
    if (currentScene != nullptr)
    {
        currentScene->Update(elapsedTime);
    }
}

//描画処理
void SceneManager::Render()
{
    if (currentScene != nullptr)
    {
        currentScene->Render();
    }
}

//シーンクリア
void SceneManager::Clear()
{
    if (currentScene != nullptr)
    {
        currentScene->Finalize();
        delete currentScene;
        currentScene = nullptr;
    }
}

//シーン切り替え
void SceneManager::ChangeScene(Scene* scene)
{
    //古いシーン終了処理
    Clear();

    //新しいシーン設定
    currentScene = scene;

    //シーン初期化処理
    currentScene->Initialize();
}