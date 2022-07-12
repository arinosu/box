#pragma once
#include "floortile.h"
#include "FloorTileStage.h"

class FloortileStage3 :public FloorTileStage
{
public:
    FloortileStage3() {}
    ~FloortileStage3()override {}

    //初期化
    void Initialize()override;

    //終了化
    void Finalize()override;

private:
    FloorTile* floortile = nullptr;
};