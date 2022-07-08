#pragma once

#include "Graphics/Shader.h"
#include "Graphics/Model.h"
#include "Character.h"

class Goal :public Character
{
public:
    Goal();
    ~Goal()override;

    //�X�V����
    void Update(float elapsedTime);

    //�`�揈��
    void Render(ID3D11DeviceContext* dc, Shader* shader);

private:
    Model* model = nullptr;
};