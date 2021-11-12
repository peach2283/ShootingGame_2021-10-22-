#include "framework.h"
#include "ShootingGame.h"

EnemyBullet::EnemyBullet(float px, float py) : Sprite("�����Ѿ�", "", true, px, py)
{
	this->speed = 250;
}

EnemyBullet::~EnemyBullet()
{}

void EnemyBullet::start()
{
	setImage("Asset/�Ѿ�1.bmp");
}

void EnemyBullet::update()
{
	float dist = speed * Time::deltaTime;
	translate(0, dist);
}

void EnemyBullet::onTrigger(GameObject* other)
{
	
}