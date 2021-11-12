#include "framework.h"
#include "ShootingGame.h"

EnemyBullet::EnemyBullet(float px, float py) : Sprite("Àû±âÃÑ¾Ë", "", true, px, py)
{
	this->speed = 250;
}

EnemyBullet::~EnemyBullet()
{}

void EnemyBullet::start()
{
	setImage("Asset/ÃÑ¾Ë1.bmp");
}

void EnemyBullet::update()
{
	float dist = speed * Time::deltaTime;
	translate(0, dist);
}

void EnemyBullet::onTrigger(GameObject* other)
{
	
}