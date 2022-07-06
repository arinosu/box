#pragma once

#include "Graphics/Graphics.h"

class Goal
{
public:
    Goal();
    ~Goal();

    //更新処理
    void Update(float elapsedTime);

    //描画処理
    void Render(ID3D11DeviceContext* dc, Shader* shader);

private:
    Model* model = nullptr;
};