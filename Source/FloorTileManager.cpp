#include "FloorTileManager.h"
#include "Collision.h"

//更新処理
void FloorTileManager::Update(float elapsedTime)
{
    for (FloorTile* floortile : floortiles)
    {
        floortile->Update(elapsedTime);
    }

    //破棄処理
    //※enemiesの範囲for文中でerase()すると不具合が発生してしまうため、
    //更新処理が終わった後に破棄リストに積まれたオブジェクトを削除する。
    for (FloorTile* floortile : removes)
    {
        //std::vectorから要素を削除する場合はイテレーターで削除しなければならない
        std::vector<FloorTile*>::iterator it = std::find(floortiles.begin(), floortiles.end(), floortile);
        if (it != floortiles.end())
        {
            floortiles.erase(it);
        }

        //削除
        delete floortile;
    }
    //破棄リストをクリア
    removes.clear();
}

//描画処理
void FloorTileManager::Render(ID3D11DeviceContext* context, Shader* shader)
{
    for (FloorTile* floortile : floortiles)
    {
        floortile->Render(context, shader);
    }
}

//フロアタイル登録
void FloorTileManager::Register(FloorTile* floortile)
{
    floortiles.emplace_back(floortile);
}

//エネミー削除
void FloorTileManager::Remove(FloorTile* floortile)
{
    //破棄リストに追加
    removes.emplace_back(floortile);
}

//フロアタイル全削除
void FloorTileManager::Clear()
{
    for (FloorTile* floortile : floortiles)
    {
        delete floortile;
    }
    floortiles.clear();
}

//デバッグプリミティブ描画
void FloorTileManager::DrawDebugPrimitive()
{
    for (FloorTile* floortile : floortiles)
    {
        floortile->DrawDebugPrimitive();
    }
}