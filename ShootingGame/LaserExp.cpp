#include "framework.h"
#include "ShootingGame.h"

LaserExp::LaserExp(float px, float py) : Animation("", "", true, px, py)
{}

LaserExp::~LaserExp()
{}

void LaserExp::start()
{
	//애니메이션 로드하기//
	for (int row = 0; row < 5; row++)  //가로줄 (열)
	{
		for (int col = 0; col < 5; col++) //세로줄(오)
		{
			addImage("Asset/레이저폭발.bmp", col * 36, row * 36, 36, 36, 0);
		}
	}

	//애니메이션속도
	setImageDelay(0.002);
}

void LaserExp::onAnimationEnd()
{
	destroy(this);
}