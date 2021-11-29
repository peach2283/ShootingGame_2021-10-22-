#include "framework.h"
#include "ShootingGame.h"

Cannon::Cannon(float px, float py) : Sprite("보스캐논","",true, px, py)
{
	this->hp = 100;
}

Cannon::~Cannon()
{}

void Cannon::start()
{
	setImage("Asset/보스.bmp", 357, 262, 21, 22);
	addBoxCollider2D(new BoxCollider2D(3, 0, 15, 22));
}

void Cannon::onTrigger(GameObject* other)
{
	string tag = other->getTag();

	if (tag == "레이저")
	{	
		//체력을 감소//
		hp = hp - 20; 

		//체력이 모두 감소하면..폭발/제거//
		if (hp <= 0)
		{
			explode();
		}
	}
	else if (tag == "폭탄폭발")
	{
		explode();
	}
}

void Cannon::explode()
{
	//폭발
	float px = getPx();
	float py = getPy();

	instantiate(new EnemyExp(px - 50, py - 50));

	//제거
	destroy(this);
}