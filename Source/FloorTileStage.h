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

    //�X�V����
    virtual void Update(float elapsedTime) = 0;

    int i = 100;
};