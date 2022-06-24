#pragma once

#include <DirectXMath.h>

//カメラコントローラー
class CameraController
{
public:
    CameraController() {}
    ~CameraController() {}

    //更新処理
    void Update(float elapsedTime);

    //ターゲット位置決定
    void SetTarget(const DirectX::XMFLOAT3& target) { this->target = target; }

private:
    DirectX::XMFLOAT3 target = { 0,0,0 };
    DirectX::XMFLOAT3 angle = { -0.1f,-0.8f,0 };
    float rollSpeed = DirectX::XMConvertToRadians(40);
    float range = 13.0f;
    float maxAngle = DirectX::XMConvertToRadians(45);
    float minAngle = DirectX::XMConvertToRadians(-45);
};