#pragma once

#include "Graphics/Shader.h"
#include "Graphics/Model.h"
#include "Character.h"

//ステージ
class Stage :public Character
{
public:
    Stage();
    ~Stage()override;

    //更新処理
    void Update(float elapsedTime);

    //描画処理
    void Render(ID3D11DeviceContext* dc, Shader* shader);

    //移動処理
    void move(float elapsedTime);

private:
    Model* model = nullptr;
};