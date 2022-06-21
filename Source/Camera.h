#pragma once

#include <DirectXMath.h>

//�J����
class Camera
{
private:   //�V���O���g�������邽�߂ɃR���X�g���N�^���v���C�x�[�g������
    Camera() {}
    ~Camera() {}

public:
    //�B��̃C���X�^���X�擾
    static Camera& Instance()
    {
        //�J�����͗l�X�ȏ��ŏ������o�������̂ŁA���E�Ɉ�������݂��Ȃ��V���O���g���ɂ���
        static Camera camera;
        return camera;
    }

    //�w�����������
    void SetLookAt(const DirectX::XMFLOAT3& eye, const DirectX::XMFLOAT3& focus, const DirectX::XMFLOAT3& up);

    //�p�[�X�y�N�e�B�u�ݒ�
    void SetPerspectiveFov(float fovY, float aspect, float nearZ, float farZ);

    //�r���[�s��擾
    const DirectX::XMFLOAT4X4& GetView()const { return view; }

    //�v���W�F�N�V�����s��擾
    const DirectX::XMFLOAT4X4& GetProjection()const { return projection; }

private:
    DirectX::XMFLOAT4X4 view;
    DirectX::XMFLOAT4X4 projection;
};