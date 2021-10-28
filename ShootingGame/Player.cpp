#include "framework.h"
#include "ShootingGame.h"

Player::Player(float px, float py) : Sprite("","", true, px, py)
{
	this->speed = 200;

	this->fireTimer = 0;
	this->fireDelay = 0.2;
}

Player::~Player()
{}

void Player::start()
{
	setImage("Asset/플레이어.bmp");
}

void Player::update()
{
	move();
	fire();
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

		if (py < 0)
		{
			setPy(0);
		}
	}

	if (Input::getKey(KeyCode::downArrow) == true)
	{
		translate(0, dist);

		//플레이어가 하단 경계벗어남 방지
		float py = getPy();

		if (py > HEIGHT - 91)
		{
			setPy(HEIGHT - 91);
		}
	}

	if (Input::getKey(KeyCode::leftArrow) == true)
	{
		translate(-dist, 0);

		//플레이어가 왼쪽 경계벗어남을 방지
		float px = getPx();

		if (px < 0)
		{
			setPx(0);
		}
	}

	if (Input::getKey(KeyCode::rightArrow) == true)
	{
		translate(dist, 0);

		//플레이어가 오른쪽 경계벗어만을 방지
		float px = getPx();

		if (px > WIDTH - 68)
		{
			setPx(WIDTH - 68);
		}
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

			///한발 발사하기//
			ObjectManager::instantiate(new Laser(px + 31, py - 20));

			///두발 발사하기//
			//ObjectManager::instantiate(new Laser(px + 26, py - 20));
			//ObjectManager::instantiate(new Laser(px + 36, py - 20));

			//세발 발사하기//
			//ObjectManager::instantiate(new Laser(px + 23, py - 15));  //왼쪽
			//ObjectManager::instantiate(new Laser(px + 31, py - 25));  //가운데..
			//ObjectManager::instantiate(new Laser(px + 39, py - 15));  //오른쪽

			fireTimer = 0;
		}
	}

}