#pragma once

#include "floortile.h"
#include "FloorTileStage.h"

class FloortileStage1:public FloorTileStage
{
public:
    FloortileStage1() {}
    ~FloortileStage1()override {}

    //������
    void Initialize()override;

    //�I����
    void Finalize()override;

private:
    FloorTile* floortile = nullptr;
};