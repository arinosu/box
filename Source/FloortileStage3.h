#pragma once
#include "floortile.h"
#include "FloorTileStage.h"

class FloortileStage3 :public FloorTileStage
{
public:
    FloortileStage3() {}
    ~FloortileStage3()override {}

    //‰Šú‰»
    void Initialize()override;

    //I—¹‰»
    void Finalize()override;

    //XVˆ—
    void Update(float elapsedTime)override;

private:
    FloorTile* floortile = nullptr;
};