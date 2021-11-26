#include "framework.h"
#include "ShootingGame.h"

Boss::Boss(float px, float py) : Sprite("","",true, px, py)
{}

Boss::~Boss()
{}

void Boss::start()
{
	//보스 기본이미지 로드 하기//
	setImage("Asset/보스.bmp", 0, 0, 493, 206);
}