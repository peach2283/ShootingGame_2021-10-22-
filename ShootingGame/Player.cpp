#include "framework.h"
#include "ShootingGame.h"

Player::Player(float px, float py) : Animation("플레이어","", true, px, py)
{
	this->speed = 200;

	this->fireTimer = 0;
	this->fireDelay = 0.2;

	this->hp		= 100;
	this->state		= State::up;
	this->fireCount = 1;
	this->bombCount = 3;
}

Player::~Player()
{}

void Player::start()
{
	//애니메이션...이미지 추가하기//	
	//가운데..이동하지 않는 애니메이션 - 0 번//
	addImage("Asset/팬텀이동2.bmp", 192, 0, 62, 80, 0);

	//오른쪽..이동 애니메이션 - 1 번//
	addImage("Asset/팬텀이동2.bmp", 192 + 64 * 0, 0, 62, 80, 1);
	addImage("Asset/팬텀이동2.bmp", 192 + 64 * 1, 0, 62, 80, 1);
	addImage("Asset/팬텀이동2.bmp", 192 + 64 * 2, 0, 62, 80, 1);
	addImage("Asset/팬텀이동2.bmp", 192 + 64 * 3, 0, 62, 80, 1);

	//왼쪽...이동 애니메이션 - 2번
	addImage("Asset/팬텀이동2.bmp", 192 - 64 * 0, 0, 62, 80, 2);
	addImage("Asset/팬텀이동2.bmp", 192 - 64 * 1, 0, 62, 80, 2);
	addImage("Asset/팬텀이동2.bmp", 192 - 64 * 2, 0, 62, 80, 2);
	addImage("Asset/팬텀이동2.bmp", 192 - 64 * 3, 0, 62, 80, 2);

	//애니메이션..루푸(loop) 옵션 지정//
	setLoop(false);

	//애니메이션..이미지 딜레이 옵션 지정//
	setImageDelay(0.1);

	//충돌체 추가하기//
	addBoxCollider2D(new BoxCollider2D(24, 5,  14, 65));
	addBoxCollider2D(new BoxCollider2D(5 , 42, 52, 15));

	//방패 자식객체 추가하기
	addChildObject(new Shield(-12, -10), 2);
}

void Player::update()
{
	switch (state)
	{
		case State::up  :  //플레이어 등장 상태
		{
			float dist = speed * Time::deltaTime;
			translate(0, -dist);

			float py = getPy();

			if (py <= HEIGHT - 150)
			{
				state = State::control;              //control 상태전이
				 
				/************방패 숨기기******************/
				//GameObject* shield = find("방패");    //방패자식객체 찾기

				//if (shield != nullptr)
				//{
				//	shield->setActive(false);             //방패자식객체..비활성화하기  
				//}
				//else {
				//	cout << "방패 자식객체를 찾을수 없음" << endl;
				//}

				/**************방패제거******************/
				GameObject * shield=find("방패");

				if (shield != nullptr)
				{
					destroy(shield);
				}
				else {
					cout << "방패 자식객체를 찾을 수 없음" << endl;
				}
			}
		}
		break;

		case State::control : //플레이어 키입력 콘트롤 상태
		{
			move();
			fire();
		}
		break;
	}

}

void Player::move()  //이동 함수
{
	///////////////이동하기//////////////
	float dist = speed * Time::deltaTime;

	//이동키 입력받기
	if (Input::getKey(KeyCode::upArrow) == true)
	{
		translate(0, -dist);

		//플레이어가 상단 경계벗어남 방지
		float py = getPy();

		if (py < -5)
		{
			setPy(-5);
		}
	}

	if (Input::getKey(KeyCode::downArrow) == true)
	{
		translate(0, dist);

		//플레이어가 하단 경계벗어남 방지
		float py = getPy();

		if (py > HEIGHT - 73)
		{
			setPy(HEIGHT - 73);
		}
	}

	if (Input::getKey(KeyCode::leftArrow) == true)
	{
		translate(-dist, 0);

		//애니메이션..변경하기
		play(2);

		//플레이어가 왼쪽 경계벗어남을 방지
		float px = getPx();

		if (px < -9)
		{
			setPx(-9);
		}
	}

	if (Input::getKey(KeyCode::rightArrow) == true)
	{
		translate(dist, 0);

		//애니메이션 변경하기
		play(1);

		//플레이어가 오른쪽 경계벗어만을 방지
		float px = getPx();

		if (px > WIDTH - 53)
		{
			setPx(WIDTH - 53);
		}
	}

	//좌우..이동키 입력이 없을때...
	if (Input::getKey(KeyCode::leftArrow) != true && Input::getKey(KeyCode::rightArrow) != true)
	{
		//애니메이션 변경하기
		play(0);
	}
}

void Player::fire()  //발사 함수
{
	////////레이저 발사하기////////
	if (Input::getKey(KeyCode::space) == true)
	{
		fireTimer = fireTimer + Time::deltaTime;

		if (fireTimer >= fireDelay)
		{
			float px = getPx();
			float py = getPy();

			if (fireCount == 1)
			{
				///한발 발사하기//
				instantiate(new Laser(px + 29, py - 20));
			}
			else if (fireCount == 2)
			{
				///두발 발사하기//
				instantiate(new Laser(px + 24, py - 20));
				instantiate(new Laser(px + 34, py - 20));
			}
			else if (fireCount == 3)
			{
				//세발 발사하기//
				instantiate(new Laser(px + 21, py - 15));  //왼쪽
				instantiate(new Laser(px + 29, py - 25));  //가운데..
				instantiate(new Laser(px + 37, py - 15));  //오른쪽
			}

			fireTimer = 0;
		}
	}

	//폭탄 발사하기
	if (Input::getKeyDown(KeyCode::Z) == true)
	{
		if (bombCount > 0)
		{
			float px = getPx();
			float py = getPy();

			instantiate(new Bomb(px + 15, py - 15));

			bombCount--; //폭탄갯수 감소
		}
		else {
			cout << "남은 폭탄이 없습니다." << endl;
		}
	}

}

void Player::onTrigger(GameObject* other)
{
	string tag = other->getTag();

	if (tag == "적기총알") 
	{
		damage(10);
	}
	else if (tag == "적기")
	{
		damage(50);
	}
	else if (tag == "총알아이템")  //플레이어 레이저발사 갯수 증가 아이템
	{
		if (fireCount < 3)
		{
			fireCount++;
		}
	}
	else if (tag == "폭탄아이템") //플레이어 폭탄갯수 증가 아이템
	{
		bombCount++;  //폭탄 최대갯수는 나중에 고려함
	}
}

void Player::damage(float amount)
{
	//hp = hp - amount;

	if (hp <= 0)
	{
		//플레이어 폭발//
		float px = getPx();
		float py = getPy();

		instantiate(new PlayerExp(px - 33, py - 27));

		//플레이어 제거//
		destroy(this);

		//플레이어 리스폰 시도하기
		GameManager::reSpawnPlayer();
	}
}