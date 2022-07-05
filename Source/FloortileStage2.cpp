#include "FloortileStage2.h"
#include "FloortileManager.h"
#include "Floortilebox.h"
#include "Box.h"

void FloortileStage2::Initialize()
{
	//�����͐G��Ȃ���
	FloorTileManager& floortilemanager = FloorTileManager::Instance();

	//  0�ŌŒ�G��Ȃ� ���̐���
	//���̔�       ��       ��
	for (int i = 0; i < 15; ++i)  //�����̐�����ς���΃u���b�N�̐���ς����
	{
		//�����͐G��Ȃ���
		FloorTileBox* box = new FloorTileBox();

		//                                 �Œ�  ����  �Œ�@�@�@�@
		//�����Ńu���b�N�̈ʒu��ݒ�ł���     ��    ��     ���@�@�@�@�@//�Œ�͐����ς��Ȃ��悤��
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 0, i * 1.4f));  //�Œ�Ə����Ă��鏊�͂��̂܂܃R�s�yOK


		//�����͐G��Ȃ���
		floortilemanager.Register(box);
	}

	for (int i = 0; i < 1; ++i)
	{
		Box* box = new Box();
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 2.0f, i * 2.7f + 10));
		box->SetAngle(DirectX::XMFLOAT3(89.5f, 0.0f, 0.0f));
		floortilemanager.Register(box);
	}

	//   0�ŌŒ�G��Ȃ� ���̐���
	//��̔�       ��       ��
	for (int i = 0; i < 15; ++i)  //�����̐�����ς���΃u���b�N�̐���ς����
	{
		//�����͐G��Ȃ���
		FloorTileBox* box = new FloorTileBox();

		//                                 �Œ�  ����     �Œ�
		//�����Ńu���b�N�̈ʒu��ݒ�ł���     ��     ��       ��
		box->SetPosition(DirectX::XMFLOAT3(0.0f, 10, i * 1.4f));


		//�����͐G��Ȃ���
		floortilemanager.Register(box);
	}

	//�u���b�N�𑝂₵��������for����S���R�s�y���ău���b�N���ƍ�����ς���
	//��for���Ƃ� for{} ������̒��g���R�s�y���č����ƃu���b�N����ύX���ăX�e�[�W�쐬���Ă���
}


void FloortileStage2::Finalize()
{
	//���̏I����
	FloorTileManager::Instance().Clear();
}

void FloortileStage2::Update(float elapsedTime)
{
	//����邱�Ƃ��Ȃ�
}