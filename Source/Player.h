#pragma once

#include "Graphics/Shader.h"
#include "Graphics/Model.h"
#include "Character.h"
#include "Effect.h"

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

    //�d�͔��]
    void GravityInverse(float elapsedTime);

    //���͏����X�V
    void UpdateVelocity(float elapsedTime);

    //�f�o�b�O�v���~�e�B�u�`��
    void DrawDebugPrimitive();

private:
    //�v���C���[�Ɣ��Ƃ̏Փˏ�������
    void CollisionPlayerVsFloortile();

private:
    Model* model = nullptr;
    Effect* effect = nullptr;
    float ADJUST = 0.0125f;
    float rolling = 12.0f;
    float gravity = 0.0f;
    int count = 0;

    bool Reverse = false; // true:�㑖�s�@false:�����s
};