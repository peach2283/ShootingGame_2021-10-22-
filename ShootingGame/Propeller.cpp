#include "framework.h"
#include "ShootingGame.h"

Propeller::Propeller(float px, float py) : Animation("보스자식","",true,px , py)
{
	this->hp = 100;
}

Propeller::~Propeller()
{}

void Propeller::start()
{
	//피해없는 프로펠러 - 0 번 애니메이션//
	addImage("Asset/보스.bmp", 7 + 34 * 0, 439, 32, 12, 0);
	addImage("Asset/보스.bmp", 7 + 34 * 1, 439, 32, 12, 0);

	//연기나는 프로펠러 - 1 번 애니메이션//
	addImage("Asset/보스.bmp", 7 + 34 * 0, 455, 32, 52, 1);
	addImage("Asset/보스.bmp", 7 + 34 * 1, 455, 32, 52, 1);

	//애니메이션 속도 지정
	setImageDelay(0.1);

	//충돌체 추가
	addBoxCollider2D(new BoxCollider2D(6, 0, 20, 12));
}

void Propeller::onTrigger(GameObject* other)
{
	string tag = other->getTag();

	if (tag == "레이저")
	{
		hp = hp - 20;

		if (0 < hp && hp <= 50)
		{
			//피해를 받은 애니메이션으로 변경
			play(1);
		}
		else if (hp <= 0)
		{
			explode();
		}
	}
	else if (tag == "폭탄폭발")
	{
		explode();
	}
}

void Propeller::explode()
{
	//폭발		
	float px = getPx();
	float py = getPy();

	instantiate(new EnemyExp(px - 50, py - 50));

	//제거
	destroy(this);
}