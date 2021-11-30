#include "framework.h"
#include "ShootingGame.h"

Gun::Gun(float px, float py) : BossSpriteChild("보스자식","",true, px, py, 50, 50)
{}

Gun::~Gun()
{}

void Gun::start()
{
	setImage("Asset/보스.bmp", 426, 315, 20, 25);
	addBoxCollider2D(new BoxCollider2D(0, 0, 20, 20));
}