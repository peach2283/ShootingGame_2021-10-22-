#include "framework.h"
#include "ShootingGame.h"

Player::Player(float px, float py) : Sprite("","", true, px, py)
{
	this->speed = 200;
}

Player::~Player()
{}

void Player::start()
{
	setImage("Asset/플레이어.bmp");
}

void Player::update()
{
	float dist = speed * Time::deltaTime;

	//이동키 입력받기
	if (GetAsyncKeyState(VK_UP) != 0)
	{
		translate(0, -dist);

		//플레이어가 상단 경계벗어남 방지
		float py = getPy();

		if (py < 0)
		{
			setPy(0);
		}
	}

	if (GetAsyncKeyState(VK_DOWN) != 0)
	{
		translate(0, dist);

		//플레이어가 하단 경계벗어남 방지
		float py = getPy();

		if (py > HEIGHT - 91)
		{
			setPy(HEIGHT - 91);
		}
	}

	if (GetAsyncKeyState(VK_LEFT) != 0)
	{
		translate(-dist, 0);

		//플레이어가 왼쪽 경계벗어남을 방지
		float px = getPx();

		if (px < 0)
		{
			setPx(0);
		}
	}

	if (GetAsyncKeyState(VK_RIGHT) != 0)
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