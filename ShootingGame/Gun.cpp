#include "framework.h"
#include "ShootingGame.h"

Gun::Gun(float px, float py, string name) : BossSpriteChild("보스자식", name ,true, px, py, 50, 50)
{}

Gun::~Gun()
{}

void Gun::start()
{
	setImage("Asset/보스.bmp", 426, 315, 20, 25);
	addBoxCollider2D(new BoxCollider2D(0, 0, 20, 20));
}

void Gun::fire()
{
	float px = getPx();
	float py = getPy();

	instantiate(new EnemyBullet(px, py+20));
}