#pragma once
#include "floortile.h"
#include "FloorTileStage.h"

class FloortileStage2 :public FloorTileStage
{
public:
    FloortileStage2() {}
    ~FloortileStage2()override {}

    //初期化
    void Initialize()override;

    //終了化
    void Finalize()override;

private:
    FloorTile* floortile = nullptr;
};