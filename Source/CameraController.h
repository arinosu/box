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

    //�J�����ړ�
    void SetSpeed(const float speed) { this->cameraSpeed += speed; }

private:
    DirectX::XMFLOAT3 target = { 0,0,0 };
    DirectX::XMFLOAT3 angle = { 0,0,0 };
    float cameraSpeed = 0.0f;
    float range = 10.0f;
    bool CameraChange = false;   // true:���]���Ȃ��@false:���]
    float roll = 0; 

    //���̕ϐ��̓X�e�[�W�쐬�̎��ɂ����̂ŏI�������폜
    float rollSpeed = DirectX::XMConvertToRadians(180);
    float maxAngle = DirectX::XMConvertToRadians(180);
    float minAngle = DirectX::XMConvertToRadians(-180);
};