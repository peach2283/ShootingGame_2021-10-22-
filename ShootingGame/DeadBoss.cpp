#include "framework.h"
#include "ShootingGame.h"

DeadBoss::DeadBoss(float px, float py) : Sprite("","",true, px, py)
{}

DeadBoss::~DeadBoss()
{}

void DeadBoss::start()
{
	//보스 폭발 후 이미지로 변경		
	setImage("Asset/보스.bmp", 0, 613, 385, 182);
}