#include "BoxManager.h"
#include "Collision.h"

//�X�V����
void BoxManager::Update(float elapsedTime)
{
    for (FloorTile* floortile : boxes)
    {
        floortile->Update(elapsedTime);
    }

    //�j������
    for (FloorTile* floortile : removes)
    {
        //std::vector����v�f���폜����ꍇ�̓C�e���[�^�[�ō폜���Ȃ���΂Ȃ�Ȃ�
        std::vector<FloorTile*>::iterator it = std::find(boxes.begin(), boxes.end(), floortile);
        if (it != boxes.end())
        {
            boxes.erase(it);
        }

        //�폜
        delete floortile;
    }
    //�j�����X�g���N���A
    removes.clear();
}

//�`�揈��
void BoxManager::Render(ID3D11DeviceContext* context, Shader* shader)
{
    for (FloorTile* floortile : boxes)
    {
        floortile->Render(context, shader);
    }
}

//��Q���o�^
void BoxManager::Register(FloorTile* floortile)
{
    boxes.emplace_back(floortile);
}

//��Q���폜
void BoxManager::Remove(FloorTile* floortile)
{
    //�j�����X�g�ɒǉ�
    removes.emplace_back(floortile);
}

//��Q���S�폜
void BoxManager::Clear()
{
    for (FloorTile* floortile : boxes)
    {
        delete floortile;
    }
    boxes.clear();
}

//�f�o�b�O�v���~�e�B�u�`��
void BoxManager::DrawDebugPrimitive()
{
    for (FloorTile* floortile : boxes)
    {
        floortile->DrawDebugPrimitive();
    }
}