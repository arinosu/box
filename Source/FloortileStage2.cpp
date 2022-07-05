#include "FloortileStage2.h"
#include "FloortileManager.h"
#include "Floortilebox.h"
#include "Box.h"

void FloortileStage2::Initialize()
{
	//ここは触らないで
	FloorTileManager& floortilemanager = FloorTileManager::Instance();

	//  0で固定触らない この数字
	//下の箱       ↓       ↓
	for (int i = 0; i < 15; ++i)  //ここの数字を変えればブロックの数を変えれる
	{
		//ここは触らないで
		FloorTileBox* box = new FloorTileBox();

		//                                 固定  高さ  固定　　　　
		//ここでブロックの位置を設定できる     ↓    ↓     ↓　　　　　//固定は数字変えないように
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 0, i * 1.4f));  //固定と書いている所はそのままコピペOK


		//ここは触らないで
		floortilemanager.Register(box);
	}

	for (int i = 0; i < 1; ++i)
	{
		Box* box = new Box();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 2.0f, i * 2.7f + 10));
		box->SetAngle(DirectX::XMFLOAT3(89.5f, 0.0f, 0.0f));
		floortilemanager.Register(box);
	}

	//   0で固定触らない この数字
	//上の箱       ↓       ↓
	for (int i = 0; i < 15; ++i)  //ここの数字を変えればブロックの数を変えれる
	{
		//ここは触らないで
		FloorTileBox* box = new FloorTileBox();

		//                                 固定  高さ     固定
		//ここでブロックの位置を設定できる     ↓     ↓       ↓
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 10, i * 1.4f));


		//ここは触らないで
		floortilemanager.Register(box);
	}

	//ブロックを増やしたい時はfor文を全部コピペしてブロック数と高さを変える
	//※for文とは for{} ←これの中身をコピペして高さとブロック数を変更してステージ作成していく
}


void FloortileStage2::Finalize()
{
	//箱の終了化
	FloorTileManager::Instance().Clear();
}

void FloortileStage2::Update(float elapsedTime)
{
	//今やることがない
}