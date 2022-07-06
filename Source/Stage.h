#pragma once

#include "Graphics/Shader.h"
#include "Graphics/Model.h"
#include "Character.h"

//�X�e�[�W
class Stage :public Character
{
public:
    Stage();
    ~Stage()override;

    //�X�V����
    void Update(float elapsedTime);

    //�`�揈��
    void Render(ID3D11DeviceContext* dc, Shader* shader);

    //�ړ�����
    void move(float elapsedTime);

private:
    Model* model = nullptr;
};