#include "framework.h"
#include "ShootingGame.h"

Player::Player(float px, float py) : Animation("플레이어","", true, px, py)
{
	this->speed = 200;

	this->fireTimer = 0;
	this->fireDelay = 0.2;
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
	addBoxCollider2D(new BoxCollider2D(0, 0, 62, 80));
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

			///한발 발사하기//
			instantiate(new Laser(px + 29, py - 20));

			///두발 발사하기//
			//instantiate(new Laser(px + 24, py - 20));
			//instantiate(new Laser(px + 34, py - 20));

			//세발 발사하기//
			//instantiate(new Laser(px + 21, py - 15));  //왼쪽
			//instantiate(new Laser(px + 29, py - 25));  //가운데..
			//instantiate(new Laser(px + 37, py - 15));  //오른쪽

			fireTimer = 0;
		}
	}
}