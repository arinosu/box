#pragma once

#include <DirectXMath.h>

//�L�����N�^�[
class Character
{
public:
    Character() {}
    virtual ~Character() {}      //�p������N���X��virtual�����邱�Ɓu�p����̃f�X�g���N�^���Ă΂��Ȃ�����v

    //�ʒu�擾
    const DirectX::XMFLOAT3& GetPosition()const { return position; }

    //�ʒu����
    void SetPosition(const DirectX::XMFLOAT3& position) { this->position = position; }

    //��]�擾
    const DirectX::XMFLOAT3& GetAngle()const { return angle; }

    //��]�ݒ�
    void SetAngle(const DirectX::XMFLOAT3& angle) { this->angle = angle; }

    //�X�P�[���擾
    const DirectX::XMFLOAT3& GetScale()const { return scale; }

    //�X�P�[���擾
    void SetScale(const DirectX::XMFLOAT3& scale) { this->scale = scale; }

    //���a�擾
    float GetRadius()const { return radius; }

    //�����擾
    float GetHeight()const { return height; }

    //�s��X�V����
    void UpdateTransform();

protected:   //�p����ł��A�N�Z�X�ł���悤�ɂ��邽��
    DirectX::XMFLOAT3 position = { 0,0,0 };  //�ʒu
    DirectX::XMFLOAT3 angle = { 0,0,0 };     //��]
    DirectX::XMFLOAT3 scale = { 1,1,1 };     //�X�P�[��
    DirectX::XMFLOAT4X4 transform = {
        1,0,0,0,
        0,1,0,0,
        0,0,1,0,
        0,0,0,1
    };               //��L��XMFLOAT3���g���s����`����
    DirectX::XMFLOAT3 velocity = { 0,0,0 };
    float radius = 0.5f;
    float height = 2.0f;
    float friction = 0.5f;
};