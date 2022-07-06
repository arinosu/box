#include "Stage.h"

//コンストラクタ
Stage::Stage()
{
    //ステージモデルを読み込む
    model = new Model("Data/Model/ExampleStage/ExampleStage.mdl");
}

Stage::~Stage()
{
    //ステージモデルを破棄
    delete model;
}

//更新処理
void Stage::Update(float elapsedTime)
{
    //今は特にやることはない
    move(elapsedTime);

    //オブジェクト行列を更新
    UpdateTransform();

    //モデル行列更新
    model->UpdateTransform(transform);
}

//描画処理
void Stage::Render(ID3D11DeviceContext* dc, Shader* shader)
{
    //シェーダーにモデルを描画してもらう
    shader->Draw(dc, model);
}

//移動処理
void Stage::move(float elapsedTime)
{
    float speed = 10.0f * elapsedTime;
    position.z += speed;
}
