#pragma once

#include "Graphics/Model.h"
#include "FloorTile.h"

//�{�b�N�X
class FloorTileBox :public FloorTile
{
public:
    FloorTileBox();
    ~FloorTileBox() override;

    //�X�V����
    void Update(float elapsedTime)override;

    //�`�揈��
    void Render(ID3D11DeviceContext* dc, Shader* shader)override;

private:
    Model* model = nullptr;
};