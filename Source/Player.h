#pragma once

#include "Graphics/Shader.h"
#include "Graphics/Model.h"
#include "Character.h"

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
    void GravityInversion(float elapsedTime);

    //速力処理更新
    void UpdateVelocity(float elapsedTime);

    //ジャンプ入力処理
    void InputJump();

    //デバッグプリミティブ描画
    void DrawDebugPrimitive();

private:
    //プレイヤーと箱との衝突処理
    void CollisionPlayerVsFloortile();

private:
    Model* model = nullptr;
    float ADJUST = 0.7f;
    float jumpSpeed = 20.0f;
    float rolling = 12.0f;
    float gravity = -1.0f;

    // true...地面に着地している
    bool onGround = true;
    bool skyGround = true;
};