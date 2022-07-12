#pragma once

#include "Graphics/Shader.h"
#include "Graphics/Model.h"

//�X�e�[�W
class Stage
{
public:
    Stage();
    ~Stage();

    //�B��̃C���X�^���X�擾
    static Stage& Instance()
    {
        static Stage instance;
        return instance;
    }

    //�X�V����
    void Update(float elapsedTime);

    //�`�揈��
    void Render(ID3D11DeviceContext* dc, Shader* shader);

    int Select(static int number_) 
    { 
        number = number_; 
        return number;
    };

    int number = 0;
private:
    Model* model = nullptr;
};