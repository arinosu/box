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
	//7 下
	for (int i = 0; i < 15; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 3.3f, i * 2.7f + 143));
		floortilemanager.Register(box);
	}
	//8 障害物
	for (int i = 0; i < 1; ++i)
	{
		Box* box = new Box();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 21.5f, i * 2.7f + 147.3f));
		box->SetAngle(DirectX::XMFLOAT3(89.5f, 0.0f, 0.0f));
		boxmanager.Register(box);
	}
	//9 上
	for (int i = 0; i < 20; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 23, i * 2.7f + 149));
		floortilemanager.Register(box);
	}
	//10 障害物
	for (int i = 0; i < 1; ++i)
	{
		Box* box = new Box();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 5.3f, i * 2.7f + 182.5f));
		box->SetAngle(DirectX::XMFLOAT3(89.5f, 0.0f, 0.0f));
		boxmanager.Register(box);
	}
	//11 下
	for (int i = 0; i < 25; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 6.8f, i * 2.7f + 184));
		floortilemanager.Register(box);
	}
	//12 障害物
	for (int i = 0; i < 1; ++i)
	{
		Box* box = new Box();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 21.5f, i * 2.7f + 202.2f));
		box->SetAngle(DirectX::XMFLOAT3(89.5f, 0.0f, 0.0f));
		boxmanager.Register(box);
	}
	//13 上
	for (int i = 0; i < 45; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 32, i * 2.7f + 250));
		floortilemanager.Register(box);
	}
	//14 障害物
	for (int i = 0; i < 1; ++i)
	{
		Box* box = new Box();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 30.5f, i * 2.7f + 320));
		box->SetAngle(DirectX::XMFLOAT3(89.5f, 0.0f, 0.0f));
		boxmanager.Register(box);
	}
	//15 中間
	for (int i = 0; i < 5; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 17, i * 2.7f + 270));
		floortilemanager.Register(box);
	}
	//16 中間
	for (int i = 0; i < 5; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 17, i * 2.7f + 320));
		floortilemanager.Register(box);
	}
	//17 中間
	for (int i = 0; i < 5; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 17, i * 2.7f + 370));
		floortilemanager.Register(box);
	}
	//18 下
	for (int i = 0; i < 40; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, -2, i * 2.7f + 280));
		floortilemanager.Register(box);
	}
	//19 障害物
	for (int i = 0; i < 1; ++i)
	{
		Box* box = new Box();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 0, i * 2.7f + 365));
		box->SetAngle(DirectX::XMFLOAT3(89.5f, 0.0f, 0.0f));
		boxmanager.Register(box);
	}
	//20 上よりの中間
	for (int i = 0; i < 25; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 23, i * 2.7f + 383));
		floortilemanager.Register(box);
	}
	//21 下
	for (int i = 0; i < 18; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 6, i * 2.7f + 400));
		floortilemanager.Register(box);
	}
	//22 下
	for (int i = 0; i < 22; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, -2, i * 2.7f + 445));
		floortilemanager.Register(box);
	}
	//23 障害物
	for (int i = 0; i < 1; ++i)
	{
		Box* box = new Box();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 0, i * 2.7f + 503.5f));
		box->SetAngle(DirectX::XMFLOAT3(89.5f, 0.0f, 0.0f));
		boxmanager.Register(box);
	}
	//24 上よりの中間
	for (int i = 0; i < 30; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 16, i * 2.7f + 485));
		floortilemanager.Register(box);
	}
	//25 上
	for (int i = 0; i < 10; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 21, i * 2.7f + 560));
		floortilemanager.Register(box);
	}
	//26 上
	for (int i = 0; i < 15; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 26, i * 2.7f + 585));
		floortilemanager.Register(box);
	}
	//27 下
	for (int i = 0; i < 15; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 8, i * 2.7f + 590));
		floortilemanager.Register(box);
	}
	//28 上
	for (int i = 0; i < 10; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 16, i * 2.7f + 610));
		floortilemanager.Register(box);
	}
	//29 上の中間あたり
	for (int i = 0; i < 10; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 11, i * 2.7f + 635));
		floortilemanager.Register(box);
	}
	//30 中間
	for (int i = 0; i < 10; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 6, i * 2.7f + 660));
		floortilemanager.Register(box);
	}
	//31 下
	for (int i = 0; i < 30; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, -13, i * 2.7f + 666));
		floortilemanager.Register(box);
	}
}

void FloortileStage2::Finalize()
{
	//箱の終了化
	FloorTileManager::Instance().Clear();

	//障害物の終了化
	BoxManager::Instance().Clear();
}