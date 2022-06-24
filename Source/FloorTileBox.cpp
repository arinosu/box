#include "FloorTileBox.h"
#include "Collision.h"

//コンストラクタ
FloorTileBox::FloorTileBox()
{
    model = new Model("Data/Model/Hako/hako.mdl");

    //モデルが大きいのでスケーリング
    scale.x = scale.y = scale.z = 0.01f;

    //幅、高さ設定
    radius = 0.6f;
    height = 1.5f;
}

//デストラクタ
FloorTileBox::~FloorTileBox()
{
    delete model;
}

//更新処理
void FloorTileBox::Update(float elapsedTime)
{
    //オブジェクト行列を更新
    UpdateTransform();

    //モデル行列更新
    model->UpdateTransform(transform);
}

//描画処理
void FloorTileBox::Render(ID3D11DeviceContext* dc, Shader* shader)
{
    shader->Draw(dc, model);
}