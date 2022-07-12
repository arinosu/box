#pragma once

#include "Graphics/Sprite.h"
#include "Scene.h"
#include "Graphics/Shader.h"
#include "Graphics/Model.h"
#include <thread>

//ローディングシーン
class SceneLoading :public Scene
{
public:
    SceneLoading(Scene* nextScene) :nextScene(nextScene) {}
    ~SceneLoading()override {}

    //初期化
    void Initialize()override;

    //終了化
    void Finalize()override;

    //更新処理
    void Update(float elapsedTime)override;

    //描画処理
    void Render()override;

private:
    //ローディングスレッド
    static void LoadingThread(SceneLoading* scene);

    //描画処理
    void RENDER(ID3D11DeviceContext* dc, Shader* shader);

    //行列更新処理
    void UpdateTransform();

    DirectX::XMFLOAT3 position = { 0,0,0 };  //位置
    DirectX::XMFLOAT3 angl = { 0,0,0 };     //回転
    DirectX::XMFLOAT3 scale = { 1,1,1 };     //スケール
    DirectX::XMFLOAT4X4 transform = {
        1,0,0,0,
        0,1,0,0,
        0,0,1,0,
        0,0,0,1
    };               //上記のXMFLOAT3を使い行列を定義する

private:
    Sprite* sprite = nullptr;
    float angle = 0.0f;
    Scene* nextScene = nullptr;
    std::thread* thread = nullptr;
    Model* model = nullptr;
};
