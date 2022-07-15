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

    //�ړ�����
    void move(float elapsedTime);

    //�X�e�[�W����
    int Select(static int number_)
    {
        number = number_;
        return number;
    };

    int number = 0;
private:
    Model* model = nullptr;
};