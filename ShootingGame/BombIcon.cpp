#include "framework.h"
#include "ShootingGame.h"

BombIcon::BombIcon(float px, float py) : Sprite("","",true, px, py)
{}

BombIcon::~BombIcon()
{}

void BombIcon::start()
{
	setImage("Asset/UI/��ź������.bmp");
}