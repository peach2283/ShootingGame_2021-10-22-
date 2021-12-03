#include "framework.h"
#include "ShootingGame.h"

Cannon::Cannon(float px, float py) :BossSpriteChild("보스자식","",true, px, py, 50, 50)
{
	this->fireTimer = 0;
	this->fireDelay = 2;
}

Cannon::~Cannon()
{}

void Cannon::start()
{
	setImage("Asset/보스.bmp", 357, 262, 21, 22);
	addBoxCollider2D(new BoxCollider2D(3, 0, 15, 22));
}

void Cannon::update()
{
	fireTimer = fireTimer + Time::deltaTime;

	if (fireTimer >= fireDelay)
	{
		float px = getPx();
		float py = getPy();

		for (int i = 0; i < 36; i++)
		{
			instantiate(new CannonBall(px, py+20, i*10));
		}

		fireTimer = 0;
	}
}