#pragma once

#include <DirectXMath.h>

using namespace DirectX;

//ƒRƒŠƒWƒ‡ƒ“
class Collision
{
public:
    //‰~’Œ‚Æ‰~’Œ‚ÌŒğ·”»’è“ªã
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