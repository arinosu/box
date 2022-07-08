#include "Goal.h"
#include "Graphics/Graphics.h"

//�R���X�g���N�^
Goal::Goal()
{
    //�S�[�����f����ǂݍ���
    model = new Model("Data/Model/Goal/goal.mdl");

    //���f�����傫���̂ŃX�P�[�����O�A���܂肵�Ȃ��ق����ǂ�
    scale.x = scale.y = scale.z = 1.20f;
}

Goal::~Goal()
{
    //�S�[�����f����j��
    delete model;
}

//�X�V����
void Goal::Update(float elapsedTime)
{
    //�I�u�W�F�N�g�s����X�V
    UpdateTransform();

    //���f���s��X�V
    model->UpdateTransform(transform);
}

//�`�揈��
void Goal::Render(ID3D11DeviceContext* dc, Shader* shader)
{
    //�V�F�[�_�[�Ƀ��f����`�悵�Ă��炤
    shader->Draw(dc, model);
}