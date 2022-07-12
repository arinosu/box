#include "Collision.h"

//円柱と円柱の交差判定頭上
bool Collision::IntersectCylinderVsCylinder(
    const DirectX::XMFLOAT3& positionA,
    float radiusA,
    float heightA,
    const DirectX::XMFLOAT3& positionB,
    float radiusB,
    float heightB,
    DirectX::XMFLOAT3& outPositionB)
{
    //Aの足元がBの頭より上なら当たっていない
    if (positionA.y > positionB.y + heightB)
    {
        return false;
    }
    //Aの頭がBの足元より下なら当たっていない
    if (positionA.y + heightA < positionB.y)
    {
        return false;
    }

    ////Bの足元がAの頭より上なら当たっていない
    //if (positionB.y > positionA.y + heightA)
    //{
    //    return false;
    //}
    ////Bの頭がAの足元より下なら当たっていない
    //if (positionB.y + heightB < positionA.y)
    //{
    //    return false;
    //}

    //XZ平面での範囲チェック
    float vx = positionB.x - positionA.x;
    float vz = positionB.z - positionA.z;
    float range = radiusA + radiusB;
    float distXZ = sqrtf(vx * vx + vz * vz);
    if (distXZ > range)
    {
        return false;
    }

    //０割りされないようにするため
    vx = distXZ != 0.0f ? vx /= distXZ : vx;
    vz = distXZ != 0.0f ? vz /= distXZ : vz;

#if false
    //AがBを押し出す
    outPositionB.x = positionA.x + (vx * range);
    outPositionB.y = positionA.y;
    outPositionB.z = positionA.z + (vz * range);
#else
    //AがBを押し出さない
    outPositionB.x = positionB.x + (vx * range);
    outPositionB.y = positionA.y;
    outPositionB.z = positionB.z - (vz * range);
#endif
    return true;
}