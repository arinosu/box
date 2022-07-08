#pragma once

class FloorTileStage
{
public:
    FloorTileStage() {}
    virtual ~FloorTileStage() {}

    //‰Šú‰»
    virtual void Initialize() = 0;

    //I—¹‰»
    virtual void Finalize() = 0;

    //XVˆ—
    virtual void Update(float elapsedTime) = 0;

    int i = 100;
};