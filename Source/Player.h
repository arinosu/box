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

    static Player& Instance()
    {
        static Player instance;
        return instance;
    }

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

    //���C�t�Z�b�g
    void SetLife(const bool life_) { life = life_; }

    //���ʂƂ��̔���
    bool GetLife() { return life; }

    //���S����
    void Death();

    //�Q�[���N���A���o 1,2,3 �X�e�[�W���ɈႤ�̂Œ���
    void Clear1(float elapsedTime);
    void Clear2(float elapsedTime);
    void Clear3(float elapsedTime);

private:
    //�v���C���[�Ɣ��Ƃ̏Փˏ�������
    void CollisionPlayerVsFloortile();

    //�v���C���[�Ə�Q���Ƃ̏Փˏ�������
    void CollisionPlayerVsBox();

private:
    Model* model = nullptr;
    Effect* effect[2] = {};
    float ADJUST = 0.0125f;
    float gravity = 0.0f;
    float moveSpeed = 0.0f;
    bool life = true;
    bool Reverse = false; // true:�㑖�s�@false:�����s
};