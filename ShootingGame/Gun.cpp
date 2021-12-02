#include "framework.h"
#include "ShootingGame.h"

Gun::Gun(float px, float py, string name) : BossSpriteChild("�����ڽ�", name ,true, px, py, 50, 50)
{}

Gun::~Gun()
{}

void Gun::start()
{
	setImage("Asset/����.bmp", 426, 315, 20, 25);
	addBoxCollider2D(new BoxCollider2D(0, 0, 20, 20));
}

void Gun::fire()
{
	float px = getPx();
	float py = getPy();

	instantiate(new EnemyBullet(px, py+20));
}