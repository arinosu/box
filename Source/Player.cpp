#include <imgui.h>
#include "Player.h"
#include "FloorTileManager.h"
#include "Collision.h"
#include "Graphics/Graphics.h"
#include "Input/Input.h"
#include "SceneOver.h"
#include "SceneManager.h"
#include "BoxManager.h"

//コンストラクタ
Player::Player()
{
    model = new Model("Data/Model/Car/car.mdl");

    //モデルが大きいのでスケーリング、あまりしないほうが良い
    scale.x = scale.y = scale.z = 0.25f;

    //ヒットエフェクトを読み込む
    effect = new Effect("Data/Effect/fire.efkefc");

    height = 1.1f;
    radius = 1.6f;
}

//デストラクタ
Player::~Player()
{
    delete effect;

    delete model;
}

//更新処理
void Player::Update(float elapsedTime)
{
    //移動操作
    Walk(elapsedTime);

    //エフェクトのポジションを更新
    effect->SetPosition(0, position);

    //速力処理更新
    UpdateVelocity(elapsedTime);

    //重力反転
    GravityInverse(elapsedTime);

    //プレイヤーと箱との衝突処理頭上
    CollisionPlayerVsFloortile();

    //オブジェクト行列を更新
    UpdateTransform();

    //モデル行列更新
    model->UpdateTransform(transform);

    //死亡処理
    if (GetLife() == true)
    {
        Death();
    }

}

//描画処理
void Player::Render(ID3D11DeviceContext* dc, Shader* shader)
{
    shader->Draw(dc, model);
}

//デバッグプリミティブ描画
void Player::DrawDebugPrimitive()
{
    DebugRenderer* debugRenderer = Graphics::Instance().GetDebugRenderer();

    //衝突判定用のデバッグを描画
    debugRenderer->DrawCylinder(position, radius, height, DirectX::XMFLOAT4(0, 0, 0, 1));
}

//プレイヤーと箱との衝突処理頭上
void Player::CollisionPlayerVsFloortile()
{
    FloorTileManager& floortilemanager = FloorTileManager::Instance();

    //全ての箱と総当たりで衝突処理
    int floortileCount = floortilemanager.GetFloortileCount();
    for (int i = 0; i < floortileCount; ++i)
    {
        FloorTile* floortile = floortilemanager.GetEnemy(i);

        //衝突処理
        DirectX::XMFLOAT3 outPosition;
        if (Collision::IntersectCylinderVsCylinder(
            position,
            radius,
            height,
            floortile->GetPosition(),
            floortile->GetRadius(),
            floortile->GetHeight(),
            outPosition))
        {
            // 下走行の場合の押し出し
            if (!Reverse && position.y > floortile->GetPosition().y)
            {
                // Y速度(重力)を0にする
                velocity.y = 0.0f;

                // XZ平面は修正しない
                outPosition.x = position.x;
                outPosition.z = position.z;

                // Y平面は上に押し出す(BOXの上に乗る)
                outPosition.y = floortile->GetPosition().y + floortile->GetHeight() + ADJUST;

                // 計算した値でプレイヤーを押し出す
                this->SetPosition(outPosition);
            }
            // 上走行の場合の押し出し
            else if (Reverse && position.y < floortile->GetPosition().y)
            {
                // Y速度(重力)を0にする
                velocity.y = 0.0f;

                // XZ平面は修正しない
                outPosition.x = position.x;
                outPosition.z = position.z;

                // Y平面は下に押し出す(BOXの下に乗る)
                outPosition.y = floortile->GetPosition().y - height - ADJUST;

                // 計算した値でプレイヤーを押し出す
                this->SetPosition(outPosition);
            }
            // それ以外の場合はXZ平面のみ修正する
            else this->SetPosition(outPosition);
        }
    }
}

//プレイヤーと障害物との衝突処理頭上
void Player::CollisionPlayerVsBox()
{
    BoxManager& Boxmanager = BoxManager::Instance();

    //全ての箱と総当たりで衝突処理
    int BoxCount = Boxmanager.GetBoxCount();
    for (int i = 0; i < BoxCount; ++i)
    {
        FloorTile* floortile = Boxmanager.GetBox(i);

        //衝突処理
        DirectX::XMFLOAT3 outPosition;
        if (Collision::IntersectCylinderVsCylinder(
            position,
            radius,
            height,
            floortile->GetPosition(),
            floortile->GetRadius(),
            floortile->GetHeight(),
            outPosition))
        {
            //押し出し処理
            this->SetPosition(outPosition);
        }
    }
}

//デバッグ用GUI描画
void Player::DrawDebugGUI()
{
    ImGui::SetNextWindowPos(ImVec2(10, 10), ImGuiCond_FirstUseEver);
    ImGui::SetNextWindowSize(ImVec2(300, 300), ImGuiCond_FirstUseEver);

    if (ImGui::Begin("Player", nullptr, ImGuiWindowFlags_None))
    {
        //トランスフォーム
        if (ImGui::CollapsingHeader("Transform", ImGuiTreeNodeFlags_DefaultOpen))
        {
            //位置
            ImGui::InputFloat3("Position", &position.x);
            //回転
            DirectX::XMFLOAT3 a;
            a.x = DirectX::XMConvertToDegrees(angle.x);
            a.y = DirectX::XMConvertToDegrees(angle.y);
            a.z = DirectX::XMConvertToDegrees(angle.z);
            ImGui::InputFloat3("Angle", &a.x);
            angle.x = DirectX::XMConvertToRadians(a.x);
            angle.y = DirectX::XMConvertToRadians(a.y);
            angle.z = DirectX::XMConvertToRadians(a.z);
            //スケール
            ImGui::InputFloat3("Scale", &scale.x);


            ImGui::InputFloat3("Velocity", &velocity.y);
        }
    }
    ImGui::End();
}

//移動操作
void Player::Walk(float elapsedTime)
{
    float moveSpeed = 10.0f * elapsedTime;   //一秒間に1.0移動する速度
    {
        //真っ直ぐ勝手に進む
        position.z += moveSpeed;

        //エフェクトの計算
        DirectX::XMFLOAT3 T = position;
        T.y += position.x * 0.5f;
        effect->Play(position, 0.2f);
    }
}

//ジャンプ処理
void Player::SkyWalk(float speed)
{
    //上方向の力を設定
    velocity.y = speed;
}

//速力処理更新
void Player::UpdateVelocity(float elapsedTime)
{
    //経過フレーム
    float elapsedFrame = 60.0f * elapsedTime;

    //重力処理
    velocity.y += gravity * elapsedFrame;

    //移動処理
    position.y += velocity.y * elapsedTime;

    //すり抜け防止
    if (Reverse == false)
    {
        velocity.y += 0.1f;
    }

    if (Reverse == true)
    {
        velocity.y -= 0.1f;
    }
}

//重力反転
void Player::GravityInverse(float elapsedTime)
{
    GamePad& gamePad = Input::Instance().GetGamePad();

    // ここで走行の上下切り替えをする
    if (gamePad.GetButtonDown() & GamePad::BTN_A) Reverse = !Reverse;

    // 上反転(上走行)
    if (Reverse)
    {
        //重力を上方向に持っていく
        gravity = 0.3f;

        //ここで車体を回す
        angle.z = DirectX::XMConvertToRadians(180);

    }
    // 下反転(下走行)
    else if (!Reverse)
    {
        //重力を下方向に持っていく
        gravity = -0.3f;

        //ここで車体を回す
        angle.z = 0;
    }
}

// 死亡処理
void Player::Death()
{
    if (position.y < -28)
    {
        SetLife(false);
    }
    else if (position.y > 39)
    {
        SetLife(false);
    }
    else
    {
        SetLife(true);
    }
}