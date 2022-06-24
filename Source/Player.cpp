#include <imgui.h>
#include "Player.h"
#include "FloorTileManager.h"
#include "Collision.h"
#include "Graphics/Graphics.h"
#include "Input/Input.h"

//�R���X�g���N�^
Player::Player()
{
    model = new Model("Data/Model/Car/car.mdl");

    //���f�����傫���̂ŃX�P�[�����O�A���܂肵�Ȃ��ق����ǂ�
    scale.x = scale.y = scale.z = 0.01f;
}

//�f�X�g���N�^
Player::~Player()
{
    delete model;
}

//�X�V����
void Player::Update(float elapsedTime)
{
    //�ړ�����
    Walk(elapsedTime);

    //�I�u�W�F�N�g�s����X�V
    UpdateTransform();

    //�W�����v���͏���
    InputJump();

    //���͏����X�V
    UpdateVelocity(elapsedTime);

    //�d�͔��]
    GravityInverse(elapsedTime);

    //�n�ʔ���
    if (position.y > 0)
    {
        onGround = false;
    }
    else 
    {
        onGround = true;
    }

    //�v���C���[�Ɣ��Ƃ̏Փˏ���
    CollisionPlayerVsFloortile();

    //���f���s��X�V
    model->UpdateTransform(transform);
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
    debugRenderer->AABB(position, radius, height, DirectX::XMFLOAT4(0, 0, 0, 1));
}

//�v���C���[�Ɣ��Ƃ̏Փˏ���
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
            //�G�̐^��t�߂ɓ����������𔻒�
            DirectX::XMVECTOR P = DirectX::XMLoadFloat3(&position);
            DirectX::XMVECTOR E = DirectX::XMLoadFloat3(&floortile->GetPosition());
            DirectX::XMVECTOR V = DirectX::XMVectorSubtract(P, E);
            DirectX::XMVECTOR N = DirectX::XMVector3Normalize(V);
            DirectX::XMFLOAT3 normal;
            DirectX::XMStoreFloat3(&normal, N);

            // �{�b�N�X��i��ł��ꉺ�ł���n�ʂɂ͒��n���Ă��Ȃ��j
            if (onGround == false)
            {
                if (normal.y > 0.0f)
                {
                    //�{�b�N�X�̏���s
                    position.y = floortile->GetHeight();
                    SkyWalk(position.y - ADJUST);
                }
                else if (normal.y < 0.1f)
                {
                    //�{�b�N�X�̉����s
                    SkyWalk(-position.y - ADJUST);
                }
            }
            else if (onGround == true)
            {
                //�����o����̈ʒu�ݒ�
                this->SetPosition(outPosition);
            }
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
        }
    }
    ImGui::End();
}

//�ړ�����
void Player::Walk(float elapsedTime)
{
    float moveSpeed = 2.0f * elapsedTime;   //��b�Ԃ�1.0�ړ����鑬�x
    {
        //�^����������ɐi��
        position.z += moveSpeed;
    }
}

//�W�����v����
void Player::SkyWalk(float speed)
{
    //������̗͂�ݒ�
    velocity.y = speed;
}

void Player::DownWalk(float speed)
{
    //�������̗͂�ݒ�
    velocity.y = -speed;
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

    //�n�ʔ���
    if (position.y < 0.0f)
    {
        position.y = 0.0f;
        velocity.y = 0.0f;
    }
}

//�W�����v���͏���
void Player::InputJump()
{
    GamePad& gamePad = Input::Instance().GetGamePad();
    if (gamePad.GetButtonDown() & GamePad::BTN_B)
    {
        SkyWalk(jumpSpeed);
    }
}

//�d�͔��]
void Player::GravityInverse(float elapsedTime)
{
    GamePad& gamePad = Input::Instance().GetGamePad();

    //�����Ń{�^���̃J�E���g������
    if (gamePad.GetButtonDown() & GamePad::BTN_A)
    {
        count += 1;
    }

    //�㔽�]
    if (gamePad.GetButtonDown() & GamePad::BTN_A && count == 1)
    {
        //�d�͂��㑤�Ɏ����Ă���
        gravity = 0.5f;

        //BTN_A�̓X�y�[�X�L�[��
        float ay = gamePad.BTN_A;

        //�ԑ̂��񂷂��߂̏���
        float speed = rolling * elapsedTime;

        //�����Ŏԑ̂���
        angle.z = ay * speed;
    }

    //�����]
    if (gamePad.GetButtonDown() & GamePad::BTN_A && count == 2)
    {
        //�d�͂������Ɏ����Ă���
        gravity = -0.5f;

        //�����Ŏԑ̂���
        angle.z = 0;
    }

    //�����ɖ߂�
    if (gamePad.GetButtonDown() & GamePad::BTN_A && count == 2)
    {
        count = 0;
    }
}