#include "FloorTile.h"
#include "FloorTileManager.h"
#include "Graphics/Graphics.h"

//デバッグプリミティブ描画
void FloorTile::DrawDebugPrimitive()
{
    DebugRenderer* debugRenderer = Graphics::Instance().GetDebugRenderer();

    //衝突判定用のデバッグ円柱を描画
    //debugRenderer->DrawCylinder(position, radius, height, DirectX::XMFLOAT4(0, 0, 0, 1));
}

//破棄
void FloorTile::Destroy()
{
    FloorTileManager::Instance().Remove(this);
}