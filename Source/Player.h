#pragma once

#include "Graphics/Shader.h"
#include "Graphics/Model.h"
#include "Character.h"

//�v���C���[
class Player :public Character
{
public:

    Player();
    ~Player()override;

    //�f�o�b�O�pGUI�`��
    void DrawDebugGUI();

    //�X�V����
    void Update(float elapsedTime);

    //�`�揈��
    void Render(ID3D11DeviceContext* dc, Shader* shader);

    //�ړ�����
    void Walk(float elapsedTime);

    //����s����
    void SkyWalk(float speed);

    //���͏����X�V
    void UpdateVelocity(float elapsedTime);

    //�W�����v���͏���
    void InputJump();

    //�f�o�b�O�v���~�e�B�u�`��
    void DrawDebugPrimitive();

private:
    //�v���C���[�Ɣ��Ƃ̏Փˏ���
    void CollisionPlayerVsFloortile();

private:
    Model* model = nullptr;
    float jumpSpeed = 20.0f;
    float gravity = -1.0f;
};