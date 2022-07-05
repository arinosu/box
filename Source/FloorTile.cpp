#include "FloorTile.h"
#include "FloorTileManager.h"
#include "Graphics/Graphics.h"

//�f�o�b�O�v���~�e�B�u�`��
void FloorTile::DrawDebugPrimitive()
{
    DebugRenderer* debugRenderer = Graphics::Instance().GetDebugRenderer();

    //�Փ˔���p�̃f�o�b�O�~����`��
    //debugRenderer->DrawCylinder(position, radius, height, DirectX::XMFLOAT4(0, 0, 0, 1));
}

//�j��
void FloorTile::Destroy()
{
    FloorTileManager::Instance().Remove(this);
}