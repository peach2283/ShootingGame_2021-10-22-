#include "framework.h"
#include "ShootingGame.h"

Gun::Gun(float px, float py) : BossSpriteChild("�����ڽ�","",true, px, py, 50, 50)
{}

Gun::~Gun()
{}

void Gun::start()
{
	setImage("Asset/����.bmp", 426, 315, 20, 25);
	addBoxCollider2D(new BoxCollider2D(0, 0, 20, 20));
}