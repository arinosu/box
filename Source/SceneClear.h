#pragma once
#include "Graphics/Sprite.h"
#include "Scene.h"

//�Q�[���N���A
class SceneClear :public Scene
{
public:
    SceneClear() {}
    ~SceneClear()override {}

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