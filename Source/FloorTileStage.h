#pragma once

class FloorTileStage
{
public:
    FloorTileStage() {}
    virtual ~FloorTileStage() {}

    //初期化
    virtual void Initialize() = 0;

    //終了化
    virtual void Finalize() = 0;
};