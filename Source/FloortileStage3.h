#pragma once
#include "floortile.h"
#include "FloorTileStage.h"

class FloortileStage3 :public FloorTileStage
{
public:
    FloortileStage3() {}
    ~FloortileStage3()override {}

    //������
    void Initialize()override;

    //�I����
    void Finalize()override;

    //�X�V����
    void Update(float elapsedTime)override;

private:
    FloorTile* floortile = nullptr;
};