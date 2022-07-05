#pragma once

#include "Graphics/Shader.h"
#include "Graphics/Model.h"
#include "Character.h"
#include "Effect.h"

//プレイヤー
class Player :public Character
{
public:

    Player();
    ~Player()override;

    //デバッグ用GUI描画
    void DrawDebugGUI();

    //更新処理
    void Update(float elapsedTime);

    //描画処理
    void Render(ID3D11DeviceContext* dc, Shader* shader);

    //移動処理
    void Walk(float elapsedTime);

    //上歩行処理
    void SkyWalk(float speed);

    //重力反転
    void GravityInverse(float elapsedTime);

    //速力処理更新
    void UpdateVelocity(float elapsedTime);

    //デバッグプリミティブ描画
    void DrawDebugPrimitive();

private:
    //プレイヤーと箱との衝突処理頭上
    void CollisionPlayerVsFloortile();

private:
    Model* model = nullptr;
    Effect* effect = nullptr;
    float ADJUST = 0.0125f;
    float rolling = 12.0f;
    float gravity = 0.0f;
    int count = 0;

    bool Reverse = false; // true:上走行　false:下走行
};