#pragma once

#include <DirectXMath.h>

using namespace DirectX;

//�R���W����
class Collision
{
public:
    //�~���Ɖ~���̌������蓪��
    static bool IntersectCylinderVsCylinder(
        const DirectX::XMFLOAT3& positionA,
        float radiusA,
        float heightA,
        const DirectX::XMFLOAT3& positionB,
        float radiusB,
        float heightB,
        DirectX::XMFLOAT3& outPositionB
    );
};