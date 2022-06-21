#pragma once

#include <DirectXMath.h>

//キャラクター
class Character
{
public:
    Character() {}
    virtual ~Character() {}      //継承するクラスはvirtualをつけること「継承先のデストラクタが呼ばれるないから」

    //位置取得
    const DirectX::XMFLOAT3& GetPosition()const { return position; }

    //位置決定
    void SetPosition(const DirectX::XMFLOAT3& position) { this->position = position; }

    //回転取得
    const DirectX::XMFLOAT3& GetAngle()const { return angle; }

    //回転設定
    void SetAngle(const DirectX::XMFLOAT3& angle) { this->angle = angle; }

    //スケール取得
    const DirectX::XMFLOAT3& GetScale()const { return scale; }

    //スケール取得
    void SetScale(const DirectX::XMFLOAT3& scale) { this->scale = scale; }

    //半径取得
    float GetRadius()const { return radius; }

    //高さ取得
    float GetHeight()const { return height; }

    //行列更新処理
    void UpdateTransform();

protected:   //継承先でもアクセスできるようにするため
    DirectX::XMFLOAT3 position = { 0,0,0 };  //位置
    DirectX::XMFLOAT3 angle = { 0,0,0 };     //回転
    DirectX::XMFLOAT3 scale = { 1,1,1 };     //スケール
    DirectX::XMFLOAT4X4 transform = {
        1,0,0,0,
        0,1,0,0,
        0,0,1,0,
        0,0,0,1
    };               //上記のXMFLOAT3を使い行列を定義する
    DirectX::XMFLOAT3 velocity = { 0,0,0 };
    float radius = 0.5f;
    float height = 2.0f;
    float friction = 0.5f;
};