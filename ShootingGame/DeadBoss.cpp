#include "framework.h"
#include "ShootingGame.h"

DeadBoss::DeadBoss(float px, float py) : Sprite("","",true, px, py)
{}

DeadBoss::~DeadBoss()
{}

void DeadBoss::start()
{
	//���� ���� �� �̹����� ����		
	setImage("Asset/����.bmp", 0, 613, 385, 182);
}