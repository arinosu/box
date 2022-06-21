#pragma once

#include "Graphics/Shader.h"
#include "Character.h"

#include <DirectXMath.h>

//�u���b�N
class FloorTile :public Character
{
public:
    FloorTile() {}
    ~FloorTile()override {}

    //�X�V����
    virtual void Update(float elapsedTime) = 0;

    //�`�揈��
    virtual void Render(ID3D11DeviceContext* dc, Shader* shader) = 0;

    //�f�o�b�O�v���~�e�B�u�`��
    virtual void DrawDebugPrimitive();

    //�j��
    void Destroy();
};