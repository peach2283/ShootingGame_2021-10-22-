#include "framework.h"
#include "ShootingGame.h"

BombExp::BombExp(float px, float py) : Animation("폭탄폭발","",true, px, py)
{}

BombExp::~BombExp()
{}

void BombExp::start()
{
	//애니메이션 이미지들//
	for (int row = 0; row < 2; row++)
	{
		for (int col = 0; col < 6; col++)
		{
			addImage("Asset/폭탄폭발.bmp", col * 130, row * 130, 128, 128, 0);
		}
	}

	//충돌체 추가하기//
	addBoxCollider2D(new BoxCollider2D(17, 17, 94, 94));
}

void BombExp::onAnimationEnd()
{
	destroy(this);
}