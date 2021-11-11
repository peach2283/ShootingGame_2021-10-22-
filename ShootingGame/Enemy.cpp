#include "framework.h"
#include "ShootingGame.h"

Enemy::Enemy(float px, float py) : Animation("적기","",true, px, py)
{
	this->hp    = 100; //적기체력
	this->speed = 100;
	this->state = State::down;
	
}

Enemy::~Enemy()
{}

void Enemy::start()
{
	//애니메이션 이미지들..로드하기//
	//피해가 없는 적기 애니메이션 클립 - 0 번 클립//
	for (int i = 0; i < 2; i++)
	{
		addImage("Asset/적기.bmp", 1 + 200 * i, 281, 190, 137, 0);  //i번 이미지
	}

	//중간 피해를 받은 적기 애니메이션 클립 - 1 번 클립 //
	for (int i = 0; i < 4; i++)
	{
		addImage("Asset/적기.bmp", 1 + 200 * i, 141, 190, 137, 1);  //i번 이미지	
	}

	//심각한 피해를 받은 적기 애니메이션 클립 - 2 번 클립//
	for (int i = 0; i < 4; i++)
	{
		addImage("Asset/적기.bmp", 1 + 200 * i, 1, 190, 137, 2);  //i번 이미지
	}

	//충돌체 추가하기
	addBoxCollider2D(new BoxCollider2D(0,  80, 190,  25));
	addBoxCollider2D(new BoxCollider2D(88, 25 , 14, 110));
	addBoxCollider2D(new BoxCollider2D(60, 10  , 70, 15));
}

void Enemy::update()
{
	switch (state)
	{
		case State::down:
		{
			float dist = speed * Time::deltaTime;
			translate(0, dist);

			float py = getPy();

			if (py >= 60)
			{
				state = State::left;
			}

		}
		break;

		case State::left:
		{
			float dist = speed * Time::deltaTime;
			translate(-dist, 0);

			float px = getPx();

			if (px <= 0)
			{
				state = State::right;
			}
		}
		break;

		case State::right:
		{
			float dist = speed * Time::deltaTime;
			translate(dist, 0);

			float px = getPx();

			if (px >= 290)
			{
				state = State::left;
			}
		}
		break;

		case State::fall:
		{
			float dist = speed * Time::deltaTime;
			translate(0, dist);
		}
		break;
	}

}

void Enemy::onTrigger(GameObject * other)
{
	string tag = other->getTag();
	
	if (tag == "레이저")
	{
		//체력감소
		hp = hp - 10;
	
		if (70 <= hp && hp <= 100)
		{
			//피해없음
			play(0);
		}
		else if (40 <= hp && hp < 70)
		{
			//적은 피해
			play(1);
		}
		else if (0 < hp && hp < 40)
		{
			//심각한 피해..애니메이션으로 변경
			play(2);

			//추락상태로..변경하기
			state = State::fall;

		}else if (hp <= 0) //체력이 모두 소진되었는지를...검사
		{
			//적기위치
			float px = getPx();
			float py = getPy();

			//적기 폭발
			instantiate(new EnemyExp(px + 30, py + 30));

			//적기 제거
			destroy(this);
		}

	}
	else if (tag == "플레이어")
	{
		
	}
}