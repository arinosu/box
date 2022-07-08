#pragma once
#include "Graphics/Sprite.h"
#include <string>

//�V�[��
class Scene
{
public:
    Scene() {}
    virtual ~Scene() {}

    //������
    virtual void Initialize() = 0;

    //�I����
    virtual void Finalize() = 0;

    //�X�V����
    virtual void Update(float elapsedTime) = 0;

    //�`�揈��
    virtual void Render() = 0;
};