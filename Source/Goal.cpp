#include "Goal.h"

//コンストラクタ
Goal::Goal()
{
    //ゴールモデルを読み込む

}

Goal::~Goal()
{
    //ゴールモデルを破棄
}

//更新処理
void Goal::Update(float elapsedTime)
{

}

//描画処理
void Goal::Render(ID3D11DeviceContext* dc, Shader* shader)
{
    //シェーダーにモデルを描画してもらう
}