#pragma once

#include <vector>
#include "FloorTile.h"

//��Q���}�l�[�W���[
class BoxManager
{
private:
    BoxManager() {}
    ~BoxManager() {}

public:
    //�B��̃C���X�^���X�擾
    static BoxManager& Instance()
    {
        static BoxManager instance;
        return instance;
    }

    //�X�V����
    void Update(float elapsedTime);

    //�`�揈��
    void Render(ID3D11DeviceContext* dc, Shader* shader);

    //��Q���o�^
    void Register(FloorTile* floortile);

    //��Q���S�폜
    void Clear();

    //�f�o�b�O�v���~�e�B�u�`��
    void DrawDebugPrimitive();

    //��Q���폜
    void Remove(FloorTile* floortile);

    //��Q�����擾
    int GetBoxCount()const { return static_cast<int>(boxes.size()); }

    //��Q���擾
    FloorTile* GetBox(int index) { return boxes.at(index); }

private:
    std::vector<FloorTile*>boxes;
    std::vector<FloorTile*>removes;
};