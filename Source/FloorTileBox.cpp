#include "FloorTileBox.h"
#include "Collision.h"

//�R���X�g���N�^
FloorTileBox::FloorTileBox()
{
    model = new Model("Data/Model/Hako/hako.mdl");

    //���f�����傫���̂ŃX�P�[�����O
    scale.x = scale.y = scale.z = 0.01f;

    //���A�����ݒ�
    radius = 0.6f;
    height = 1.5f;
}

//�f�X�g���N�^
FloorTileBox::~FloorTileBox()
{
    delete model;
}

//�X�V����
void FloorTileBox::Update(float elapsedTime)
{
    //�I�u�W�F�N�g�s����X�V
    UpdateTransform();

    //���f���s��X�V
    model->UpdateTransform(transform);
}

//�`�揈��
void FloorTileBox::Render(ID3D11DeviceContext* dc, Shader* shader)
{
    shader->Draw(dc, model);
}