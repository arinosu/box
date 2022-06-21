#include <imgui.h>
#include "Player.h"
#include "FloorTileManager.h"
#include "Collision.h"
#include "Graphics/Graphics.h"
#include "Input/Input.h"

//コンストラクタ
Player::Player()
{
    model = new Model("Data/Model/Mr.Incredible/Mr.Incredible.mdl");

    //モデルが大きいのでスケーリング、あまりしないほうが良い
    scale.x = scale.y = scale.z = 0.01f;
}

//デストラクタ
Player::~Player()
{
    delete model;
}

//更新処理
void Player::Update(float elapsedTime)
{
    //移動操作
    Walk(elapsedTime);

    //オブジェクト行列を更新
    UpdateTransform();

    //ジャンプ入力処理
    InputJump();

    //速力処理更新
    UpdateVelocity(elapsedTime);

    //プレイヤーと箱との衝突処理
    CollisionPlayerVsFloortile();

    //モデル行列更新
    model->UpdateTransform(transform);
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
    debugRenderer->AABB(position, radius, height, DirectX::XMFLOAT4(0, 0, 0, 1));
}

//プレイヤーと箱との衝突処理
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
            //敵の真上付近に当たったかを判定
            DirectX::XMVECTOR P = DirectX::XMLoadFloat3(&position);
            DirectX::XMVECTOR E = DirectX::XMLoadFloat3(&floortile->GetPosition());
            DirectX::XMVECTOR V = DirectX::XMVectorSubtract(P, E);
            DirectX::XMVECTOR N = DirectX::XMVector3Normalize(V);
            DirectX::XMFLOAT3 normal;
            DirectX::XMStoreFloat3(&normal, N);
            if (normal.y > 0.8f)
            {
                //上を歩く
                SkyWalk(jumpSpeed * 0.05f);
            }
            else
            {
                

                //押し出し後の位置設定
                this->SetPosition(outPosition);
            }
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
        }
    }
    ImGui::End();
}

//移動操作
void Player::Walk(float elapsedTime)
{
    float moveSpeed = 1.0f * elapsedTime;   //一秒間に1.0移動する速度
    {
        //真っ直ぐ勝手に進む
        position.z += moveSpeed;
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

    //地面判定
    if (position.y < 0.0f)
    {
        position.y = 0.0f;
        velocity.y = 0.0f;
    }
}

//ジャンプ入力処理
void Player::InputJump()
{
    GamePad& gamePad = Input::Instance().GetGamePad();
    if (gamePad.GetButtonDown() & GamePad::BTN_A)
    {
        SkyWalk(jumpSpeed);
    }
}