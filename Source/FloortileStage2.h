#pragma once
#include "floortile.h"
#include "FloorTileStage.h"

class FloortileStage2 :public FloorTileStage
{
public:
    FloortileStage2() {}
    ~FloortileStage2()override {}

    //������
    void Initialize()override;

    //�I����
    void Finalize()override;

private:
    FloorTile* floortile = nullptr;
};