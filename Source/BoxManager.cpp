#include "BoxManager.h"
#include "Collision.h"

//更新処理
void BoxManager::Update(float elapsedTime)
{
    for (FloorTile* floortile : boxes)
    {
        floortile->Update(elapsedTime);
    }

    //破棄処理
    for (FloorTile* floortile : removes)
    {
        //std::vectorから要素を削除する場合はイテレーターで削除しなければならない
        std::vector<FloorTile*>::iterator it = std::find(boxes.begin(), boxes.end(), floortile);
        if (it != boxes.end())
        {
            boxes.erase(it);
        }

        //削除
        delete floortile;
    }
    //破棄リストをクリア
    removes.clear();
}

//描画処理
void BoxManager::Render(ID3D11DeviceContext* context, Shader* shader)
{
    for (FloorTile* floortile : boxes)
    {
        floortile->Render(context, shader);
    }
}

//障害物登録
void BoxManager::Register(FloorTile* floortile)
{
    boxes.emplace_back(floortile);
}

//障害物削除
void BoxManager::Remove(FloorTile* floortile)
{
    //破棄リストに追加
    removes.emplace_back(floortile);
}

//障害物全削除
void BoxManager::Clear()
{
    for (FloorTile* floortile : boxes)
    {
        delete floortile;
    }
    boxes.clear();
}

//デバッグプリミティブ描画
void BoxManager::DrawDebugPrimitive()
{
    for (FloorTile* floortile : boxes)
    {
        floortile->DrawDebugPrimitive();
    }
}