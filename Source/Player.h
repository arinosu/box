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

    static Player& Instance()
    {
        static Player instance;
        return instance;
    }

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

    //ライフセット
    void SetLife(const bool life_) { life = life_; }

    //死ぬときの判定
    bool GetLife() { return life; }

    //死亡処理
    void Death();

    //ゲームクリア演出 1,2,3 ステージ毎に違うので注意
    void Clear1(float elapsedTime);
    void Clear2(float elapsedTime);
    void Clear3(float elapsedTime);

private:
    //プレイヤーと箱との衝突処理頭上
    void CollisionPlayerVsFloortile();

    //プレイヤーと障害物との衝突処理頭上
    void CollisionPlayerVsBox();

private:
    Model* model = nullptr;
    Effect* effect[2] = {};
    float ADJUST = 0.0125f;
    float gravity = 0.0f;
    float moveSpeed = 0.0f;
    bool life = true;
    bool Reverse = false; // true:上走行　false:下走行
};