#pragma once

#include <DirectXMath.h>

//�J�����R���g���[���[
class CameraController
{
public:
    CameraController() {}
    ~CameraController() {}

    //�X�V����
    void Update(float elapsedTime);

    //�^�[�Q�b�g�ʒu����
    void SetTarget(const DirectX::XMFLOAT3& target) { this->target = target; }

private:
    DirectX::XMFLOAT3 target = { 0,0,0 };
    DirectX::XMFLOAT3 angle = { -0.1f,-0.8f,0 };
    float rollSpeed = DirectX::XMConvertToRadians(40);
    float range = 13.0f;
    float maxAngle = DirectX::XMConvertToRadians(45);
    float minAngle = DirectX::XMConvertToRadians(-45);
};