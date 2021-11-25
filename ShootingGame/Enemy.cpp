#include "framework.h"
#include "ShootingGame.h"

Enemy::Enemy(float px, float py, int num) : Animation("적기","",true, px, py)
{
	this->hp    = 100; //적기체력
	
	this->speed		= 100;
	this->fallSpeed = 200;

	this->state = State::down;
	
	this->fireTimer = 0;
	this->fireDelay = 1;

	this->downStopVar = Random::range(-80, 80);
	this->num		    = num;
	this->isItemDropped = false;
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
	/////////////이동/추락 스테이트머신///////
	switch (state)
	{
		case State::down:
		{
			float dist = speed * Time::deltaTime;
			translate(0, dist);

			float py = getPy();

			if (py >= 60 + downStopVar)
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
			float dist = fallSpeed * Time::deltaTime;
			translate(0, dist);
		}
		break;
	}

	///////////총알발사//////////////
	fireTimer = fireTimer + Time::deltaTime;

	if (fireTimer >= fireDelay)
	{
		float px = getPx();
		float py = getPy();

		instantiate(new EnemyBullet(px + 86, py + 130));

		fireTimer = 0;
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

			if (state != State::fall)
			{
				//추락상태로..변경하기
				state = State::fall;

				//추락중 폭발되지 않고..화면아래로..사라지는 경우.. destroy하기
				destroy(this, 5);
			}

		}else if (hp <= 0) //체력이 모두 소진되었는지를...검사
		{				
			explode();
		}
	}
	else if (tag == "플레이어" || tag == "폭탄폭발" || tag == "방패")
	{
		explode();
	}	
}

void Enemy::explode()
{
	//적기위치
	float px = getPx();
	float py = getPy();

	//적기 폭발
	instantiate(new EnemyExp(px + 30, py + 30), 1);

	//적기 제거
	destroy(this);

	if (isItemDropped == false)
	{
		///총알(레이저) 아이템 생성하기 //		
		if (GameManager::doDropBulletItem(num) == true)
		{
			instantiate(new BulletItem(px + 80, py + 30));
		}

		///폭탄 아아템 생성하기//
		if (GameManager::doDropBombItem(num) == true)
		{
			instantiate(new BombItem(px + 80, py + 50));
		}

		isItemDropped = true;  //아이템 생성을 했음
	}
}

void Enemy::onDestroy()
{
	//적기제거 카운트 증가
	GameManager::addEnemyDestroyCount();
}