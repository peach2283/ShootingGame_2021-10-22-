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
	setImage("Asset/�÷��̾�.bmp");
}

void Player::update()
{
	move();
	fire();
}

void Player::move()  //�̵� �Լ�
{
	///////////////�̵��ϱ�//////////////
	float dist = speed * Time::deltaTime;

	//�̵�Ű �Է¹ޱ�
	if (Input::getKey(KeyCode::upArrow) == true)
	{
		translate(0, -dist);

		//�÷��̾ ��� ����� ����
		float py = getPy();

		if (py < 0)
		{
			setPy(0);
		}
	}

	if (Input::getKey(KeyCode::downArrow) == true)
	{
		translate(0, dist);

		//�÷��̾ �ϴ� ����� ����
		float py = getPy();

		if (py > HEIGHT - 91)
		{
			setPy(HEIGHT - 91);
		}
	}

	if (Input::getKey(KeyCode::leftArrow) == true)
	{
		translate(-dist, 0);

		//�÷��̾ ���� ������� ����
		float px = getPx();

		if (px < 0)
		{
			setPx(0);
		}
	}

	if (Input::getKey(KeyCode::rightArrow) == true)
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

void Player::fire()  //�߻� �Լ�
{
	////////������ �߻��ϱ�////////
	if (Input::getKey(KeyCode::space) == true)
	{
		fireTimer = fireTimer + Time::deltaTime;

		if (fireTimer >= fireDelay)
		{
			float px = getPx();
			float py = getPy();

			///�ѹ� �߻��ϱ�//
			ObjectManager::instantiate(new Laser(px + 31, py - 20));

			///�ι� �߻��ϱ�//
			//ObjectManager::instantiate(new Laser(px + 26, py - 20));
			//ObjectManager::instantiate(new Laser(px + 36, py - 20));

			//���� �߻��ϱ�//
			//ObjectManager::instantiate(new Laser(px + 23, py - 15));  //����
			//ObjectManager::instantiate(new Laser(px + 31, py - 25));  //���..
			//ObjectManager::instantiate(new Laser(px + 39, py - 15));  //������

			fireTimer = 0;
		}
	}

}