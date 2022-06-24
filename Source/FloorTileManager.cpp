#include "FloorTileManager.h"
#include "Collision.h"

//�X�V����
void FloorTileManager::Update(float elapsedTime)
{
    for (FloorTile* floortile : floortiles)
    {
        floortile->Update(elapsedTime);
    }

    //�j������
    //��enemies�͈̔�for������erase()����ƕs����������Ă��܂����߁A
    //�X�V�������I�������ɔj�����X�g�ɐς܂ꂽ�I�u�W�F�N�g���폜����B
    for (FloorTile* floortile : removes)
    {
        //std::vector����v�f���폜����ꍇ�̓C�e���[�^�[�ō폜���Ȃ���΂Ȃ�Ȃ�
        std::vector<FloorTile*>::iterator it = std::find(floortiles.begin(), floortiles.end(), floortile);
        if (it != floortiles.end())
        {
            floortiles.erase(it);
        }

        //�폜
        delete floortile;
    }
    //�j�����X�g���N���A
    removes.clear();
}

//�`�揈��
void FloorTileManager::Render(ID3D11DeviceContext* context, Shader* shader)
{
    for (FloorTile* floortile : floortiles)
    {
        floortile->Render(context, shader);
    }
}

//�t���A�^�C���o�^
void FloorTileManager::Register(FloorTile* floortile)
{
    floortiles.emplace_back(floortile);
}

//�G�l�~�[�폜
void FloorTileManager::Remove(FloorTile* floortile)
{
    //�j�����X�g�ɒǉ�
    removes.emplace_back(floortile);
}

//�t���A�^�C���S�폜
void FloorTileManager::Clear()
{
    for (FloorTile* floortile : floortiles)
    {
        delete floortile;
    }
    floortiles.clear();
}

//�f�o�b�O�v���~�e�B�u�`��
void FloorTileManager::DrawDebugPrimitive()
{
    for (FloorTile* floortile : floortiles)
    {
        floortile->DrawDebugPrimitive();
    }
}