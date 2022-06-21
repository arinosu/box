#pragma once

#include <vector>
#include "FloorTile.h"

//�t���A�^�C���}�l�[�W���[
class FloorTileManager
{
private:
    FloorTileManager() {}
    ~FloorTileManager() {}

public:
    //�B��̃C���X�^���X�擾
    static FloorTileManager& Instance()
    {
        static FloorTileManager instance;
        return instance;
    }

    //�X�V����
    void Update(float elapsedTime);

    //�`�揈��
    void Render(ID3D11DeviceContext* dc, Shader* shader);

    //�t���A�^�C���o�^
    void Register(FloorTile* floortile);

    //�t���A�^�C���S�폜
    void Clear();

    //�f�o�b�O�v���~�e�B�u�`��
    void DrawDebugPrimitive();

    //�t���A�^�C���폜
    void Remove(FloorTile* floortile);

    //�t���A�^�C�����擾
    int GetFloortileCount()const { return static_cast<int>(floortiles.size()); }

    //�t���A�^�C���擾
    FloorTile* GetEnemy(int index) { return floortiles.at(index); }

private:
    //�����m�̏Փˏ���
    void CollisionBoxVsBox();

    std::vector<FloorTile*>floortiles;
    std::vector<FloorTile*>removes;
};