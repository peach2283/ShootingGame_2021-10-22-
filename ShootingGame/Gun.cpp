#include "framework.h"
#include "ShootingGame.h"

Gun::Gun(float px, float py) : Sprite("�����ڽ�","",true, px, py)
{}

Gun::~Gun()
{}

void Gun::start()
{
	setImage("Asset/����.bmp", 426, 315, 20, 25);
}