#include <imgui.h>
#include "Player.h"
#include "FloorTileManager.h"
#include "Collision.h"
#include "Graphics/Graphics.h"
#include "Input/Input.h"
#include "SceneOver.h"
#include "SceneManager.h"
#include "BoxManager.h"

//�R���X�g���N�^
Player::Player()
{
    model = new Model("Data/Model/Car/car.mdl");

    //���f�����傫���̂ŃX�P�[�����O�A���܂肵�Ȃ��ق����ǂ�
    scale.x = scale.y = scale.z = 0.25f;

    //�q�b�g�G�t�F�N�g��ǂݍ���
    effect = new Effect("Data/Effect/fire.efkefc");

    height = 1.1f;
    radius = 1.6f;
}

//�f�X�g���N�^
Player::~Player()
{
    delete effect;

    delete model;
}

//�X�V����
void Player::Update(float elapsedTime)
{
    //�ړ�����
    Walk(elapsedTime);

    //�G�t�F�N�g�̃|�W�V�������X�V
    effect->SetPosition(0, position);

    //���͏����X�V
    UpdateVelocity(elapsedTime);

    //�d�͔��]
    GravityInverse(elapsedTime);

    //�v���C���[�Ɣ��Ƃ̏Փˏ�������
    CollisionPlayerVsFloortile();

    //�I�u�W�F�N�g�s����X�V
    UpdateTransform();

    //���f���s��X�V
    model->UpdateTransform(transform);

    //���S����
    if (GetLife() == true)
    {
        Death();
    }

}

//�`�揈��
void Player::Render(ID3D11DeviceContext* dc, Shader* shader)
{
    shader->Draw(dc, model);
}

//�f�o�b�O�v���~�e�B�u�`��
void Player::DrawDebugPrimitive()
{
    DebugRenderer* debugRenderer = Graphics::Instance().GetDebugRenderer();

    //�Փ˔���p�̃f�o�b�O��`��
    debugRenderer->DrawCylinder(position, radius, height, DirectX::XMFLOAT4(0, 0, 0, 1));
}

//�v���C���[�Ɣ��Ƃ̏Փˏ�������
void Player::CollisionPlayerVsFloortile()
{
    FloorTileManager& floortilemanager = FloorTileManager::Instance();

    //�S�Ă̔��Ƒ�������ŏՓˏ���
    int floortileCount = floortilemanager.GetFloortileCount();
    for (int i = 0; i < floortileCount; ++i)
    {
        FloorTile* floortile = floortilemanager.GetEnemy(i);

        //�Փˏ���
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
            // �����s�̏ꍇ�̉����o��
            if (!Reverse && position.y > floortile->GetPosition().y)
            {
                // Y���x(�d��)��0�ɂ���
                velocity.y = 0.0f;

                // XZ���ʂ͏C�����Ȃ�
                outPosition.x = position.x;
                outPosition.z = position.z;

                // Y���ʂ͏�ɉ����o��(BOX�̏�ɏ��)
                outPosition.y = floortile->GetPosition().y + floortile->GetHeight() + ADJUST;

                // �v�Z�����l�Ńv���C���[�������o��
                this->SetPosition(outPosition);
            }
            // �㑖�s�̏ꍇ�̉����o��
            else if (Reverse && position.y < floortile->GetPosition().y)
            {
                // Y���x(�d��)��0�ɂ���
                velocity.y = 0.0f;

                // XZ���ʂ͏C�����Ȃ�
                outPosition.x = position.x;
                outPosition.z = position.z;

                // Y���ʂ͉��ɉ����o��(BOX�̉��ɏ��)
                outPosition.y = floortile->GetPosition().y - height - ADJUST;

                // �v�Z�����l�Ńv���C���[�������o��
                this->SetPosition(outPosition);
            }
            // ����ȊO�̏ꍇ��XZ���ʂ̂ݏC������
            else this->SetPosition(outPosition);
        }
    }
}

//�v���C���[�Ə�Q���Ƃ̏Փˏ�������
void Player::CollisionPlayerVsBox()
{
    BoxManager& Boxmanager = BoxManager::Instance();

    //�S�Ă̔��Ƒ�������ŏՓˏ���
    int BoxCount = Boxmanager.GetBoxCount();
    for (int i = 0; i < BoxCount; ++i)
    {
        FloorTile* floortile = Boxmanager.GetBox(i);

        //�Փˏ���
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
            //�����o������
            this->SetPosition(outPosition);
        }
    }
}

//�f�o�b�O�pGUI�`��
void Player::DrawDebugGUI()
{
    ImGui::SetNextWindowPos(ImVec2(10, 10), ImGuiCond_FirstUseEver);
    ImGui::SetNextWindowSize(ImVec2(300, 300), ImGuiCond_FirstUseEver);

    if (ImGui::Begin("Player", nullptr, ImGuiWindowFlags_None))
    {
        //�g�����X�t�H�[��
        if (ImGui::CollapsingHeader("Transform", ImGuiTreeNodeFlags_DefaultOpen))
        {
            //�ʒu
            ImGui::InputFloat3("Position", &position.x);
            //��]
            DirectX::XMFLOAT3 a;
            a.x = DirectX::XMConvertToDegrees(angle.x);
            a.y = DirectX::XMConvertToDegrees(angle.y);
            a.z = DirectX::XMConvertToDegrees(angle.z);
            ImGui::InputFloat3("Angle", &a.x);
            angle.x = DirectX::XMConvertToRadians(a.x);
            angle.y = DirectX::XMConvertToRadians(a.y);
            angle.z = DirectX::XMConvertToRadians(a.z);
            //�X�P�[��
            ImGui::InputFloat3("Scale", &scale.x);


            ImGui::InputFloat3("Velocity", &velocity.y);
        }
    }
    ImGui::End();
}

//�ړ�����
void Player::Walk(float elapsedTime)
{
    float moveSpeed = 10.0f * elapsedTime;   //��b�Ԃ�1.0�ړ����鑬�x
    {
        //�^����������ɐi��
        position.z += moveSpeed;

        //�G�t�F�N�g�̌v�Z
        DirectX::XMFLOAT3 T = position;
        T.y += position.x * 0.5f;
        effect->Play(position, 0.2f);
    }
}

//�W�����v����
void Player::SkyWalk(float speed)
{
    //������̗͂�ݒ�
    velocity.y = speed;
}

//���͏����X�V
void Player::UpdateVelocity(float elapsedTime)
{
    //�o�߃t���[��
    float elapsedFrame = 60.0f * elapsedTime;

    //�d�͏���
    velocity.y += gravity * elapsedFrame;

    //�ړ�����
    position.y += velocity.y * elapsedTime;

    //���蔲���h�~
    if (Reverse == false)
    {
        velocity.y += 0.1f;
    }

    if (Reverse == true)
    {
        velocity.y -= 0.1f;
    }
}

//�d�͔��]
void Player::GravityInverse(float elapsedTime)
{
    GamePad& gamePad = Input::Instance().GetGamePad();

    // �����ő��s�̏㉺�؂�ւ�������
    if (gamePad.GetButtonDown() & GamePad::BTN_A) Reverse = !Reverse;

    // �㔽�](�㑖�s)
    if (Reverse)
    {
        //�d�͂�������Ɏ����Ă���
        gravity = 0.3f;

        //�����Ŏԑ̂���
        angle.z = DirectX::XMConvertToRadians(180);

    }
    // �����](�����s)
    else if (!Reverse)
    {
        //�d�͂��������Ɏ����Ă���
        gravity = -0.3f;

        //�����Ŏԑ̂���
        angle.z = 0;
    }
}

// ���S����
void Player::Death()
{
    if (position.y < -28)
    {
        SetLife(false);
    }
    else if (position.y > 39)
    {
        SetLife(false);
    }
    else
    {
        SetLife(true);
    }
}