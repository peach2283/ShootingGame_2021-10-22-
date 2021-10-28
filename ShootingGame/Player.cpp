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
	setImage("Asset/�÷��̾�.bmp");
}

void Player::update()
{
	float dist = speed * Time::deltaTime;

	//�̵�Ű �Է¹ޱ�
	if (Input::getKey( KeyCode::upArrow ) == true)
	{
		translate(0, -dist);

		//�÷��̾ ��� ����� ����
		float py = getPy();

		if (py < 0)
		{
			setPy(0);
		}
	}

	if (Input::getKey( KeyCode::downArrow )==true)
	{
		translate(0, dist);

		//�÷��̾ �ϴ� ����� ����
		float py = getPy();

		if (py > HEIGHT - 91)
		{
			setPy(HEIGHT - 91);
		}
	}

	if (Input::getKey( KeyCode::leftArrow )==true)
	{
		translate(-dist, 0);

		//�÷��̾ ���� ������� ����
		float px = getPx();

		if (px < 0)
		{
			setPx(0);
		}
	}

	if (Input::getKey( KeyCode::rightArrow )==true)
	{
		translate(dist, 0);

		//�÷��̾ ������ ������� ����
		float px = getPx();

		if (px > WIDTH - 68)
		{
			setPx(WIDTH - 68);
		}
	}
}