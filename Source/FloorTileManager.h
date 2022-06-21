#pragma once

#include <vector>
#include "FloorTile.h"

//フロアタイルマネージャー
class FloorTileManager
{
private:
    FloorTileManager() {}
    ~FloorTileManager() {}

public:
    //唯一のインスタンス取得
    static FloorTileManager& Instance()
    {
        static FloorTileManager instance;
        return instance;
    }

    //更新処理
    void Update(float elapsedTime);

    //描画処理
    void Render(ID3D11DeviceContext* dc, Shader* shader);

    //フロアタイル登録
    void Register(FloorTile* floortile);

    //フロアタイル全削除
    void Clear();

    //デバッグプリミティブ描画
    void DrawDebugPrimitive();

    //フロアタイル削除
    void Remove(FloorTile* floortile);

    //フロアタイル数取得
    int GetFloortileCount()const { return static_cast<int>(floortiles.size()); }

    //フロアタイル取得
    FloorTile* GetEnemy(int index) { return floortiles.at(index); }

private:
    //箱同士の衝突処理
    void CollisionBoxVsBox();

    std::vector<FloorTile*>floortiles;
    std::vector<FloorTile*>removes;
};