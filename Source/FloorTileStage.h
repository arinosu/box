#pragma once

class FloorTileStage
{
public:
    FloorTileStage() {}
    virtual ~FloorTileStage() {}

    //������
    virtual void Initialize() = 0;

    //�I����
    virtual void Finalize() = 0;
};