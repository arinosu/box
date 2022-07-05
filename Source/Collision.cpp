#include "Collision.h"

//�~���Ɖ~���̌������蓪��
bool Collision::IntersectCylinderVsCylinder(
    const DirectX::XMFLOAT3& positionA,
    float radiusA,
    float heightA,
    const DirectX::XMFLOAT3& positionB,
    float radiusB,
    float heightB,
    DirectX::XMFLOAT3& outPositionB)
{
    //A�̑�����B�̓�����Ȃ瓖�����Ă��Ȃ�
    if (positionA.y > positionB.y + heightB)
    {
        return false;
    }
    //A�̓���B�̑�����艺�Ȃ瓖�����Ă��Ȃ�
    if (positionA.y + heightA < positionB.y)
    {
        return false;
    }

    ////B�̑�����A�̓�����Ȃ瓖�����Ă��Ȃ�
    //if (positionB.y > positionA.y + heightA)
    //{
    //    return false;
    //}
    ////B�̓���A�̑�����艺�Ȃ瓖�����Ă��Ȃ�
    //if (positionB.y + heightB < positionA.y)
    //{
    //    return false;
    //}

    //XZ���ʂł͈̔̓`�F�b�N
    float vx = positionB.x - positionA.x;
    float vz = positionB.z - positionA.z;
    float range = radiusA + radiusB;
    float distXZ = sqrtf(vx * vx + vz * vz);
    if (distXZ > range)
    {
        return false;
    }

    //�O���肳��Ȃ��悤�ɂ��邽��
    vx = distXZ != 0.0f ? vx /= distXZ : vx;
    vz = distXZ != 0.0f ? vz /= distXZ : vz;

#if false
    //A��B�������o��
    outPositionB.x = positionA.x + (vx * range);
    outPositionB.y = positionA.y;
    outPositionB.z = positionA.z + (vz * range);
#else
    //A��B�������o���Ȃ�
    outPositionB.x = positionB.x + (vx * range);
    outPositionB.y = positionA.y;
    outPositionB.z = positionB.z - (vz * range);
#endif
    return true;
}