#pragma once

#include "Graphics/Graphics.h"

class Goal
{
public:
    Goal();
    ~Goal();

    //�X�V����
    void Update(float elapsedTime);

    //�`�揈��
    void Render(ID3D11DeviceContext* dc, Shader* shader);

private:
    Model* model = nullptr;
};