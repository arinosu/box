#include "Goal.h"
#include "Graphics/Graphics.h"

//コンストラクタ
Goal::Goal()
{
    //ゴールモデルを読み込む
    model = new Model("Data/Model/Goal/goal.mdl");

    //モデルが大きいのでスケーリング、あまりしないほうが良い
    scale.x = scale.y = scale.z = 1.20f;
}

Goal::~Goal()
{
    //ゴールモデルを破棄
    delete model;
}

//更新処理
void Goal::Update(float elapsedTime)
{
    //オブジェクト行列を更新
    UpdateTransform();

    //モデル行列更新
    model->UpdateTransform(transform);
}

//描画処理
void Goal::Render(ID3D11DeviceContext* dc, Shader* shader)
{
    //シェーダーにモデルを描画してもらう
    shader->Draw(dc, model);
}