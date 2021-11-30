#include "framework.h"
#include "ShootingGame.h"

BossSpriteChild::BossSpriteChild(string tag, string name, bool active, float px, float py, float ex, float ey)
				:Sprite(tag, name, active, px, py)
{
	this->hp = 100;
	this->ex = ex;
	this->ey = ey;
}

BossSpriteChild::~BossSpriteChild()
{}

void BossSpriteChild::onTrigger(GameObject* other)
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

void BossSpriteChild::explode()
{
	//폭발
	float px = getPx();
	float py = getPy();

	instantiate(new EnemyExp(px - ex, py - ey));

	//제거
	destroy(this);
}