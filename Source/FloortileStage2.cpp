#include "FloortileStage2.h"
#include "FloortileManager.h"
#include "Floortilebox.h"
#include "Box.h"
#include "BoxManager.h"

void FloortileStage2::Initialize()
{
	//情報を持ってくる
	FloorTileManager& floortilemanager = FloorTileManager::Instance();
	BoxManager& boxmanager = BoxManager::Instance();

	//1 下
	for (int i = 0; i < 20; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 0, i * 2.7f));
		floortilemanager.Register(box);
	}
	//2 上
	for (int i = 0; i < 16; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 23.0f, i * 2.7f + 50));
		floortilemanager.Register(box);
	}
	//3 障害物
	for (int i = 0; i < 1; ++i)
	{
		Box* box = new Box();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 21.5f, i * 2.7f + 92.5f));
		box->SetAngle(DirectX::XMFLOAT3(89.5f, 0.0f, 0.0f));
		boxmanager.Register(box);
	}
	//4 下
	for (int i = 0; i < 21; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 0, i * 2.7f + 86));
		floortilemanager.Register(box);
	}
	//5 上
	for (int i = 0; i < 20; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 19.5f, i * 2.7f + 94.3f));
		floortilemanager.Register(box);
	}
	//6 障害物
	for (int i = 0; i < 1; ++i)
	{
		Box* box = new Box();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 1.9f, i * 2.7f + 142));
		box->SetAngle(DirectX::XMFLOAT3(89.5f, 0.0f, 0.0f));
		boxmanager.Register(box);
	}
	//6 下
	for (int i = 0; i < 15; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 3.3f, i * 2.7f + 143));
		floortilemanager.Register(box);
	}
	//7 障害物
	for (int i = 0; i < 1; ++i)
	{
		Box* box = new Box();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 21.5f, i * 2.7f + 148));
		box->SetAngle(DirectX::XMFLOAT3(89.5f, 0.0f, 0.0f));
		boxmanager.Register(box);
	}
	//8 上
	//for (int i = 0; i < 20; ++i)
	//{
	//	FloorTileBox* box = new FloorTileBox();
	//	box->SetPosition(DirectX::XMFLOAT3(0.0f, 19.5f, i * 2.7f + 94.3f));
	//	floortilemanager.Register(box);
	//}
}


void FloortileStage2::Finalize()
{
	//箱の終了化
	FloorTileManager::Instance().Clear();

	//障害物の終了化
	BoxManager::Instance().Clear();
}

void FloortileStage2::Update(float elapsedTime)
{
	//今やることがない
}