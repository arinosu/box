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

    //唯一のインスタンス取得
    static Stage& Instance()
    {
        static Stage instance;
        return instance;
    }

    //更新処理
    void Update(float elapsedTime);

    //描画処理
    void Render(ID3D11DeviceContext* dc, Shader* shader);

    //移動処理
    void move(float elapsedTime);

    //ステージ差別
    int Select(static int number_)
    {
        number = number_;
        return number;
    };

    int number = 0;
private:
    Model* model = nullptr;
};