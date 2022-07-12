#pragma once
#include "floortile.h"
#include "FloorTileStage.h"

class FloortileStage2 :public FloorTileStage
{
public:
    FloortileStage2() {}
    ~FloortileStage2()override {}

    //‰Šú‰»
    void Initialize()override;

    //I—¹‰»
    void Finalize()override;

    //XVˆ—
    void Update(float elapsedTime)override;

private:
    FloorTile* floortile = nullptr;
};