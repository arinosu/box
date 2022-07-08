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
    DirectX::XMFLOAT3 angle = { 0,0,0 };
    float range = 10.0f;
    bool CameraChange = false;   // true:反転しない　false:反転

    float rollSpeed = DirectX::XMConvertToRadians(200);
    float maxAngle = DirectX::XMConvertToRadians(180);
    float minAngle = DirectX::XMConvertToRadians(-180);
};