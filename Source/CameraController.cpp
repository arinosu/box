#include "CameraController.h"
#include "Camera.h"
#include "Input/Input.h"

//�X�V����
void CameraController::Update(float elapsedTime)
{
    GamePad& gamePad = Input::Instance().GetGamePad();

    //--���̏����̓X�e�[�W�쐬�̂��߂Ɏg���̂ŏI�������폜---------
    float ax = gamePad.GetAxisRX();
    float ay = gamePad.GetAxisRY();
    //�J�����̉�]���x
    float speed = rollSpeed * elapsedTime;

    //�X�e�B�b�N�̓��͒l�ɍ��킹�Ăw���Ƃx������]
    angle.x += ay * speed;
    angle.y += ax * speed;

    //X���̃J������]�𐧌�
    if (angle.x > maxAngle)angle.x = maxAngle;
    if (angle.x < minAngle)angle.x = minAngle;

    //Y���̃J������]�𐧌�
    if (angle.y > maxAngle)angle.y = maxAngle;
    if (angle.y < minAngle)angle.y = minAngle;
    //-----------------------------------------------------------

        //�J������]�l����]�s��ɕϊ�
    DirectX::XMMATRIX Transform = DirectX::XMMatrixRotationRollPitchYaw(angle.x, angle.y, angle.z);

    //��]�s�񂩂�O�����x�N�g�������o��
    DirectX::XMVECTOR Front = Transform.r[2];
    DirectX::XMFLOAT3 front;
    DirectX::XMStoreFloat3(&front, Front);

    //�����_������x�N�g�������Ɉ�苗�����ꂽ�J�������_�����߂�
    DirectX::XMFLOAT3 eye;
    eye.x = target.x - front.x * range;
    eye.y = target.y - front.y * range;
    eye.z = /*cameraSpeed*/target.z - front.z * range;

    // �����ŃJ�����̏㉺�؂�ւ�������
    if (gamePad.GetButtonDown() & GamePad::BTN_A) CameraChange = !CameraChange;

    // ���](��)
    if (CameraChange)
    {
        //�J�����̎��_�ƒ����_��ݒ�
        eye.y -= 4;
        eye.x += 5;
        target.y -= 4;
        float roll = rollSpeed * elapsedTime;

        angle.y += roll;
        angle.x += roll;

        Camera::Instance().SetLookAt(eye, target, DirectX::XMFLOAT3(angle.y, -angle.x, 0));
    }
    // ���](��)
    else if (!CameraChange)
    {
        //�J�����̎��_�ƒ����_��ݒ�
        float roll = rollSpeed * elapsedTime;

        angle.y += roll;
        angle.x -= roll;

        Camera::Instance().SetLookAt(eye, target, DirectX::XMFLOAT3(angle.y, angle.x, 0));
    }
}