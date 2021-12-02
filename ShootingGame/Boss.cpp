#include "framework.h"
#include "ShootingGame.h"

Boss::Boss(float px, float py) : Sprite("보스","",true, px, py)
{
	this->speed = 50;
	this->state = State::down;

	this->fireTimer = 0;
	this->fireDelay = 0.7;

	this->fireIndex = 0;
}

Boss::~Boss()
{}

void Boss::start()
{
	//보스 기본이미지 로드 하기//
	setImage("Asset/보스.bmp", 0, 0, 493, 206);

	//프로펠러..자식객체 추가하기//
	addChildObject(new Propeller( 63, 41));
	addChildObject(new Propeller(111, 41));
	addChildObject(new Propeller(159, 41));

	addChildObject(new Propeller(302, 41));
	addChildObject(new Propeller(350, 41));
	addChildObject(new Propeller(398, 41));

	//날개 자식객체 추가하기//
	addChildObject(new Wing(256, 97 , 0 )); //오른쪽 첫번째
	addChildObject(new Wing(302, 94,  1 )); //오른쪽 두번째
	addChildObject(new Wing(350, 90,  2 )); //오른쪽 세번째
	addChildObject(new Wing(405, 84,  3 )); //오른쪽 네번째

	addChildObject(new Wing(206, 98,  4 )); //왼쪽 첫번째
	addChildObject(new Wing(158, 94,  5 )); //왼쪽 두번째
	addChildObject(new Wing(110, 90,  6 )); //왼쪽 세번째
	addChildObject(new Wing(62 , 84,  7 )); //왼쪽 네번째

	//보스 건 자식객체 추가하기//
	addChildObject(new Gun(94 , 71, "건0"));
	addChildObject(new Gun(142, 71, "건1"));
	addChildObject(new Gun(190, 71, "건2"));

	addChildObject(new Gun(238, 63 , "건3"));

	addChildObject(new Gun(286, 71, "건4"));
	addChildObject(new Gun(334, 71, "건5"));
	addChildObject(new Gun(382, 71, "건6"));

	//보스 대포 자식객체 추가하기
	addChildObject(new Cannon(265 + 5, 97 + 10));
	addChildObject(new Cannon(206 - 5, 97 + 10));

	//보스 레이더 자식객체 추가하기
	addChildObject(new Radar(241, 105));
	addChildObject(new Radar(241, 117));

	//보스 전체 충돌체 추가하기
	addBoxCollider2D(new BoxCollider2D(230,    5,   33,     170)); //가운데 몸통
	addBoxCollider2D(new BoxCollider2D(0,     60,   493,    45));  //가운데 날개
	addBoxCollider2D(new BoxCollider2D(185,   175,  123,    25));  //꼬리  날개
}

void Boss::update()
{
	//보스 스테이트 머신//
	switch (state)
	{
		case State::down:
		{
			translate(0, speed * Time::deltaTime);

			if (getPy() > 70)
			{
				state = State::attack;
			}
		}
		break;

		case State::attack:
		{
			fireTimer = fireTimer + Time::deltaTime;

			if (fireTimer >= fireDelay)
			{
				/**************보스건 발사하기*********************/
				string gunName[7] = { "건0", "건1","건2", "건3", "건4", "건5", "건6" };

				for (int i = 0; i < 7; i++)
				{
					if (fireArray[fireIndex][i] == true)
					{
						Gun* gun = (Gun*)find(gunName[i]);

						if (gun != nullptr)
						{
							gun->fire();
						}
					}
				}

				fireIndex++;

				if (fireIndex >= MAX_FIRE_LINE)
				{
					fireIndex = 0;
				}
				/************************************************/

				fireTimer = 0;
			}
		}

		break;
	}

	//남은 자식갯수 알아와서..보스 폭발 시키기//
	int count = childCount();

	if (count == 0)
	{
		float px = getPx();
		float py = getPy();

		//보스 폭발 효과
		instantiate(new EnemyExp(px + 180, py + 40), 1);

		instantiate(new EnemyExp(px + 180 + 70,  py + 40), 1);
		instantiate(new EnemyExp(px + 180 + 140, py + 40), 1);
		instantiate(new EnemyExp(px + 180 + 210, py + 40), 1);

		instantiate(new EnemyExp(px + 180 - 70,  py + 40), 1);
		instantiate(new EnemyExp(px + 180 - 140, py + 40), 1);
		instantiate(new EnemyExp(px + 180 - 210, py + 40), 1);

		instantiate(new EnemyExp(px + 180, py + 40 - 70), 1);
		instantiate(new EnemyExp(px + 180, py + 40 + 70), 1);

		//보스 객체를 제거
		destroy(this);

		//파괴된 보스 객체를...제거된 보스 위치에 생성함
		instantiate(new DeadBoss(px + 45, py+10));
	}	
}