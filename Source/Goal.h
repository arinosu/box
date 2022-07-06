#pragma once

#include "Graphics/Graphics.h"

class Goal
{
public:
    Goal();
    ~Goal();

    //XVˆ—
    void Update(float elapsedTime);

    //•`‰æˆ—
    void Render(ID3D11DeviceContext* dc, Shader* shader);

private:
    Model* model = nullptr;
};