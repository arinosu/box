#include "FloortileStage1.h"
#include "FloortileManager.h"
#include "Floortilebox.h"
#include "Box.h"
#include "BoxManager.h"

void FloortileStage1::Initialize()
{
	//���������Ă���
	FloorTileManager& floortilemanager = FloorTileManager::Instance();
	BoxManager& boxmanager = BoxManager::Instance();

	//1 ��
	for (int i = 0; i < 10; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 0, i * 2.7f));
		floortilemanager.Register(box);
	}
	//2 ��
	for (int i = 0; i < 15; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 18.0f, i * 2.7f + 26));
		floortilemanager.Register(box);
	}
	//3 ��Q��
	for (int i = 0; i < 1; ++i)
	{
		Box* box = new Box();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 16.5f, i * 2.7f + 56));
		box->SetAngle(DirectX::XMFLOAT3(89.5f, 0.0f, 0.0f));
		boxmanager.Register(box);
	}
	//4 ��
	for (int i = 0; i < 15; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 0, i * 2.7f + 50));
		floortilemanager.Register(box);
	}
	//5 ��Q��
	for (int i = 0; i < 1; ++i)
	{
		Box* box = new Box();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 2.0f, i * 2.7f + 83));
		box->SetAngle(DirectX::XMFLOAT3(89.5f, 0.0f, 0.0f));
		boxmanager.Register(box);
	}
	//6 ��
	for (int i = 0; i < 15; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 24.0f, i * 2.7f + 81));
		floortilemanager.Register(box);
	}
	//7 ��
	for (int i = 0; i < 14; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, -8.0f, i * 2.7f + 115));
		floortilemanager.Register(box);
	}
	//8 ��
	for (int i = 0; i < 12; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, -17.0f, i * 2.7f + 150));
		floortilemanager.Register(box);
	}
	//9 ��
	for (int i = 0; i < 11; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, -26.0f, i * 2.7f + 180));
		floortilemanager.Register(box);
	}
	//10 ��Q��
	for (int i = 0; i < 1; ++i)
	{
		Box* box = new Box();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, -24.0f, i * 2.7f + 205));
		box->SetAngle(DirectX::XMFLOAT3(89.5f, 0.0f, 0.0f));
		boxmanager.Register(box);
	}
	//11 ��
	for (int i = 0; i < 15; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 5.0f, i * 2.7f + 215));
		floortilemanager.Register(box);
	}
	//12 ��
	for (int i = 0; i < 20; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 20.0f, i * 2.7f + 260));
		floortilemanager.Register(box);
	}
	//13 ��Q��
	for (int i = 0; i < 1; ++i)
	{
		Box* box = new Box();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 18.5f, i * 2.7f + 280));
		box->SetAngle(DirectX::XMFLOAT3(89.5f, 0.0f, 0.0f));
		boxmanager.Register(box);
	}
	//14 ��	
	for (int i = 0; i < 10; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 3.0f, i * 2.7f + 270));
		floortilemanager.Register(box);
	}
	//15 ��Q��
	for (int i = 0; i < 1; ++i)
	{
		Box* box = new Box();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 5.0f, i * 2.7f + 290));
		box->SetAngle(DirectX::XMFLOAT3(89.5f, 0.0f, 0.0f));
		boxmanager.Register(box);
	}
	//16 ��	
	for (int i = 0; i < 10; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 12.0f, i * 2.7f + 310));
		floortilemanager.Register(box);
	}
	//17 	
	for (int i = 0; i < 12; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 27.0f, i * 2.7f + 340));
		floortilemanager.Register(box);
	}
	//18 	
	for (int i = 0; i < 10; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 12.0f, i * 2.7f + 370));
		floortilemanager.Register(box);
	}
	//19 	
	for (int i = 0; i < 9; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 31.0f, i * 2.7f + 410));
		floortilemanager.Register(box);
	}
	//20 	
	for (int i = 0; i < 8; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 7.0f, i * 2.7f + 430));
		floortilemanager.Register(box);
	}
	//21 	
	for (int i = 0; i < 7; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 25.0f, i * 2.7f + 450));
		floortilemanager.Register(box);
	}
	//22 	
	for (int i = 0; i < 15; ++i)
	{
		FloorTileBox* box = new FloorTileBox();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 3.0f, i * 2.7f + 480));
		floortilemanager.Register(box);
	}
}


void FloortileStage1::Finalize()
{
	//���̏I����
	FloorTileManager::Instance().Clear();

	//��Q���̏I����
	BoxManager::Instance().Clear();
}

void FloortileStage1::Update(float elapsedTime)
{
	//����邱�Ƃ��Ȃ�
}