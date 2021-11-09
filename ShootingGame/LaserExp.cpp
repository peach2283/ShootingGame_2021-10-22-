#include "framework.h"
#include "ShootingGame.h"

LaserExp::LaserExp(float px, float py) : Animation("", "", true, px, py)
{}

LaserExp::~LaserExp()
{}

void LaserExp::start()
{
	//�ִϸ��̼� �ε��ϱ�//
	for (int row = 0; row < 5; row++)  //������ (��)
	{
		for (int col = 0; col < 5; col++) //������(��)
		{
			addImage("Asset/����������.bmp", col * 36, row * 36, 36, 36, 0);
		}
	}

	//�ִϸ��̼Ǽӵ�
	setImageDelay(0.002);
}

void LaserExp::onAnimationEnd()
{
	destroy(this);
}