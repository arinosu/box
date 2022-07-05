#pragma once

#include "Graphics/Model.h"
#include "FloorTile.h"

//ボックス
class Box :public FloorTile
{
public:
    Box();
    ~Box() override;

    //更新処理
    void Update(float elapsedTime)override;

    //描画処理
    void Render(ID3D11DeviceContext* dc, Shader* shader)override;

private:
    Model* model = nullptr;
};