#include "framework.h"
#include "ShootingGame.h"

BulletExp::BulletExp(float px, float py) : Animation("" ,"" , true, px, py)
{}

BulletExp::~BulletExp()
{}

void BulletExp::start()
{
	for (int y = 0; y < 2; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			addImage("Asset/�Ѿ�����.bmp", x * 40, y * 40, 40, 40, 0);
		}
	}

	addImage("Asset/�Ѿ�����.bmp", 0 * 40, 2 * 40, 40, 40, 0);
	addImage("Asset/�Ѿ�����.bmp", 1 * 40, 2 * 40, 40, 40, 0);
}

void BulletExp::onAnimationEnd()
{
	destroy(this);
}