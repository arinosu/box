#include "Box.h"
#include "Collision.h"

//コンストラクタ
Box::Box()
{
    model = new Model("Data/Model/Floortile/Floortile.mdl");

    //モデルが大きいのでスケーリング
    scale.x = scale.y = scale.z = 0.1f;

    //幅、高さ設定
    radius = 1.4f;
    height = 1.5f;

}

//デストラクタ
Box::~Box()
{
    delete model;
}

//更新処理
void Box::Update(float elapsedTime)
{
    //オブジェクト行列を更新
    UpdateTransform();

    //モデル行列更新
    model->UpdateTransform(transform);
}

//描画処理
void Box::Render(ID3D11DeviceContext* dc, Shader* shader)
{
    shader->Draw(dc, model);
}