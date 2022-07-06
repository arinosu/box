#pragma once

#include <vector>
#include "FloorTile.h"

//障害物マネージャー
class BoxManager
{
private:
    BoxManager() {}
    ~BoxManager() {}

public:
    //唯一のインスタンス取得
    static BoxManager& Instance()
    {
        static BoxManager instance;
        return instance;
    }

    //更新処理
    void Update(float elapsedTime);

    //描画処理
    void Render(ID3D11DeviceContext* dc, Shader* shader);

    //障害物登録
    void Register(FloorTile* floortile);

    //障害物全削除
    void Clear();

    //デバッグプリミティブ描画
    void DrawDebugPrimitive();

    //障害物削除
    void Remove(FloorTile* floortile);

    //障害物数取得
    int GetBoxCount()const { return static_cast<int>(boxes.size()); }

    //障害物取得
    FloorTile* GetBox(int index) { return boxes.at(index); }

private:
    std::vector<FloorTile*>boxes;
    std::vector<FloorTile*>removes;
};