#pragma once

#include "floortile.h"
#include "FloorTileStage.h"

class FloortileStage1:public FloorTileStage
{
public:
    FloortileStage1() {}
    ~FloortileStage1()override {}

    //初期化
    void Initialize()override;

    //終了化
    void Finalize()override;

private:
    FloorTile* floortile = nullptr;
};