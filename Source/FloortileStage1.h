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

    //�X�V����
    void Update(float elapsedTime)override;

private:
    FloorTile* floortile = nullptr;
};