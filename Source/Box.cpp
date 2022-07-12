#include "Box.h"
#include "Collision.h"

//�R���X�g���N�^
Box::Box()
{
    model = new Model("Data/Model/Floortile/Floortile.mdl");

    //���f�����傫���̂ŃX�P�[�����O
    scale.x = scale.y = scale.z = 0.1f;

    //���A�����ݒ�
    radius = 1.4f;
    height = 1.5f;

}

//�f�X�g���N�^
Box::~Box()
{
    delete model;
}

//�X�V����
void Box::Update(float elapsedTime)
{
    //�I�u�W�F�N�g�s����X�V
    UpdateTransform();

    //���f���s��X�V
    model->UpdateTransform(transform);
}

//�`�揈��
void Box::Render(ID3D11DeviceContext* dc, Shader* shader)
{
    shader->Draw(dc, model);
}