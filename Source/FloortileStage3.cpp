#include "FloortileStage3.h"
#include "FloortileManager.h"
#include "Floortilebox.h"
#include "Box.h"
#include "BoxManager.h"

void FloortileStage3::Initialize()
{
	//情報を持ってくる
	FloorTileManager& floortilemanager = FloorTileManager::Instance();
	BoxManager& boxmanager = BoxManager::Instance();

	//1 下
	for (int i = 0; i < 17; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 0, i * 2.7f));
		floortilemanager.Register(box);
	}
	//2 下
	for (int i = 0; i < 10; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, -4, i * 2.7f + 50));
		floortilemanager.Register(box);
	}
	//3 下
	for (int i = 0; i < 10; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, -8, i * 2.7f + 80));
		floortilemanager.Register(box);
	}
	//4 下
	for (int i = 0; i < 10; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, -12, i * 2.7f + 110));
		floortilemanager.Register(box);
	}
	//5 上
	for (int i = 0; i < 15; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 4, i * 2.7f + 125));
		floortilemanager.Register(box);
	}
	//6 下
	for (int i = 0; i < 10; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, -12, i * 2.7f + 155));
		floortilemanager.Register(box);
	}
	//7 上
	for (int i = 0; i < 10; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 4, i * 2.7f + 180));
		floortilemanager.Register(box);
	}
	//8 下
	for (int i = 0; i < 15; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, -12, i * 2.7f + 200));
		floortilemanager.Register(box);
	}
	//9 上
	for (int i = 0; i < 15; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 13, i * 2.7f + 220));
		floortilemanager.Register(box);
	}
	//10 下
	for (int i = 0; i < 5; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, -4, i * 2.7f + 245));
		floortilemanager.Register(box);
	}
	//11 上
	for (int i = 0; i < 3; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 9, i * 2.7f + 265));
		floortilemanager.Register(box);
	}
	//12 下
	for (int i = 0; i < 3; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, -8, i * 2.7f + 270));
		floortilemanager.Register(box);
	}
	//13 上
	for (int i = 0; i < 3; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 5, i * 2.7f + 280));
		floortilemanager.Register(box);
	}
	//14 下
	for (int i = 0; i < 3; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, -12, i * 2.7f + 290));
		floortilemanager.Register(box);
	}
	//15 上
	for (int i = 0; i < 3; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 1, i * 2.7f + 300));
		floortilemanager.Register(box);
	}
	//16 下
	for (int i = 0; i < 3; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, -16, i * 2.7f + 310));
		floortilemanager.Register(box);
	}
	//17 上
	for (int i = 0; i < 3; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, -3, i * 2.7f + 320));
		floortilemanager.Register(box);
	}
	//18 下
	for (int i = 0; i < 10; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, -19, i * 2.7f + 330));
		floortilemanager.Register(box);
	}
	//19 上
	for (int i = 0; i < 3; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 1, i * 2.7f + 340));
		floortilemanager.Register(box);
	}
	//20 上
	for (int i = 0; i < 3; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 5, i * 2.7f + 350));
		floortilemanager.Register(box);
	}
	//21 下
	for (int i = 0; i < 3; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, -15, i * 2.7f + 365));
		floortilemanager.Register(box);
	}
	//22 上
	for (int i = 0; i < 3; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 9, i * 2.7f + 375));
		floortilemanager.Register(box);
	}
	//23 下
	for (int i = 0; i < 3; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, -11, i * 2.7f + 385));
		floortilemanager.Register(box);
	}
	//24 上
	for (int i = 0; i < 15; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 13, i * 2.7f + 390));
		floortilemanager.Register(box);
	}
	//25 下
	for (int i = 0; i < 3; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, -7, i * 2.7f + 400));
		floortilemanager.Register(box);
	}
	//26 下
	for (int i = 0; i < 15; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, -3, i * 2.7f + 420));
		floortilemanager.Register(box);
	}
	//27 上
	for (int i = 0; i < 10; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 14, i * 2.7f + 460));
		floortilemanager.Register(box);
	}
	//28 下
	for (int i = 0; i < 35; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, -5, i * 2.7f + 480));
		floortilemanager.Register(box);
	}
	//29 上
	for (int i = 0; i < 28; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 23, i * 2.7f + 500));
		floortilemanager.Register(box);
	}
	//30 障害物
	for (int i = 0; i < 1; ++i)
	{
		Box* box = new Box();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 21.5f, i * 2.7f + 574.8f));
		box->SetAngle(DirectX::XMFLOAT3(89.5f, 0.0f, 0.0f));
		boxmanager.Register(box);
	}
	//31 障害物
	for (int i = 0; i < 1; ++i)
	{
		Box* box = new Box();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, -3, i * 2.7f + 573.6f));
		box->SetAngle(DirectX::XMFLOAT3(89.5f, 0.0f, 0.0f));
		boxmanager.Register(box);
	}
	//32 中間
	for (int i = 0; i < 25; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 8, i * 2.7f + 550));
		floortilemanager.Register(box);
	}
	//33 上
	for (int i = 0; i < 15; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 22, i * 2.7f + 620));
		floortilemanager.Register(box);
	}
	//34 下
	for (int i = 0; i < 15; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, -7, i * 2.7f + 620));
		floortilemanager.Register(box);
	}
	//35 中間
	for (int i = 0; i < 20; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 8, i * 2.7f + 660));
		floortilemanager.Register(box);
	}
	//36 上
	for (int i = 0; i < 15; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 22, i * 2.7f + 720));
		floortilemanager.Register(box);
	}
	//37 下
	for (int i = 0; i < 15; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, -7, i * 2.7f + 720));
		floortilemanager.Register(box);
	}
	//38 中間
	for (int i = 0; i < 20; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 8, i * 2.7f + 760));
		floortilemanager.Register(box);
	}
	//39 障害物
	for (int i = 0; i < 1; ++i)
	{
		Box* box = new Box();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 6.5f, i * 2.7f + 813.3f));
		box->SetAngle(DirectX::XMFLOAT3(89.5f, 0.0f, 0.0f));
		boxmanager.Register(box);
	}
	//40 中間
	for (int i = 0; i < 25; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, -8, i * 2.7f + 800));
		floortilemanager.Register(box);
	}
}

void FloortileStage3::Finalize()
{
	//箱の終了化
	FloorTileManager::Instance().Clear();

	//障害物の終了化
	BoxManager::Instance().Clear();
}