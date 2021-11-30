#include "framework.h"
#include "ShootingGame.h"

Gun::Gun(float px, float py) : Sprite("보스자식","",true, px, py)
{}

Gun::~Gun()
{}

void Gun::start()
{
	setImage("Asset/보스.bmp", 426, 315, 20, 25);
}