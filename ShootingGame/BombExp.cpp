#include "framework.h"
#include "ShootingGame.h"

BombExp::BombExp(float px, float py) : Animation("��ź����","",true, px, py)
{}

BombExp::~BombExp()
{}

void BombExp::start()
{
	//�ִϸ��̼� �̹�����//
	for (int row = 0; row < 2; row++)
	{
		for (int col = 0; col < 6; col++)
		{
			addImage("Asset/��ź����.bmp", col * 130, row * 130, 128, 128, 0);
		}
	}

	//�浹ü �߰��ϱ�//
	addBoxCollider2D(new BoxCollider2D(17, 17, 94, 94));
}

void BombExp::onAnimationEnd()
{
	destroy(this);
}