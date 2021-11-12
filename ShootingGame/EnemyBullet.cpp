#include "framework.h"
#include "ShootingGame.h"

EnemyBullet::EnemyBullet(float px, float py) : Sprite("적기총알", "", true, px, py)
{
	this->speed = 250;
}

EnemyBullet::~EnemyBullet()
{}

void EnemyBullet::start()
{
	setImage("Asset/총알1.bmp");
	addBoxCollider2D(new BoxCollider2D(0, 0, 16, 15));
}

void EnemyBullet::update()
{
	float dist = speed * Time::deltaTime;
	translate(0, dist);
}

void EnemyBullet::onTrigger(GameObject* other)
{
	string tag = other->getTag();

	if (tag == "플레이어")
	{
		//적기 총알 폭발//
		float px = getPx();
		float py = getPy();

		instantiate(new BulletExp(px-5, py-5));

		//적기 총알 제거//
		destroy(this);
	}
}