#include "framework.h"
#include "ShootingGame.h"

Boss::Boss(float px, float py) : Sprite("","",true, px, py)
{}

Boss::~Boss()
{}

void Boss::start()
{
	//���� �⺻�̹��� �ε� �ϱ�//
	setImage("Asset/����.bmp", 0, 0, 493, 206);
}