#pragma once

#include "Graphics/Sprite.h"
#include "Scene.h"

//�Z���N�g�V�[��
class SceneChoice :public Scene
{
public:
    SceneChoice() {}
    ~SceneChoice()override {}

    //������
    void Initialize()override;

    //�I����
    void Finalize()override;

    //�X�V����
    void Update(float elapsedTime)override;

    //�`�揈��
    void Render()override;

private:
    Sprite* sprite = nullptr;
};