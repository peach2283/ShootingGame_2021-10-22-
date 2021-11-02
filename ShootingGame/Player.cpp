#include "framework.h"
#include "ShootingGame.h"

Player::Player(float px, float py) : Animation("","", true, px, py)
{
	this->speed = 200;

	this->fireTimer = 0;
	this->fireDelay = 0.2;
}

Player::~Player()
{}

void Player::start()
{
	//�ִϸ��̼�...�̹��� �߰��ϱ�//
	
	//���..�̵����� �ʴ� �ִϸ��̼� - 0 ��//
	addImage("Asset/�����̵�2.bmp", 192, 0, 62, 80, 0);

	//������..�̵� �ִϸ��̼� - 1 ��//
	addImage("Asset/�����̵�2.bmp", 192 + 64 *1, 0, 62, 80, 1);
	addImage("Asset/�����̵�2.bmp", 192 + 64 *2, 0, 62, 80, 1);
	addImage("Asset/�����̵�2.bmp", 192 + 64 *3, 0, 62, 80, 1);

	//�ִϸ��̼�..��Ǫ(loop) �ɼ� ����//
	setLoop(false);
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

		if (py < -5)
		{
			setPy(-5);
		}
	}

	if (Input::getKey(KeyCode::downArrow) == true)
	{
		translate(0, dist);

		//�÷��̾ �ϴ� ����� ����
		float py = getPy();

		if (py > HEIGHT - 73)
		{
			setPy(HEIGHT - 73);
		}
	}

	if (Input::getKey(KeyCode::leftArrow) == true)
	{
		translate(-dist, 0);

		//�÷��̾ ���� ������� ����
		float px = getPx();

		if (px < -9)
		{
			setPx(-9);
		}
	}

	if (Input::getKey(KeyCode::rightArrow) == true)
	{
		translate(dist, 0);

		//�ִϸ��̼� �����ϱ�
		play(1);

		//�÷��̾ ������ ������� ����
		float px = getPx();

		if (px > WIDTH - 53)
		{
			setPx(WIDTH - 53);
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
			ObjectManager::instantiate(new Laser(px + 29, py - 20));

			///�ι� �߻��ϱ�//
			//ObjectManager::instantiate(new Laser(px + 24, py - 20));
			//ObjectManager::instantiate(new Laser(px + 34, py - 20));

			//���� �߻��ϱ�//
			//ObjectManager::instantiate(new Laser(px + 21, py - 15));  //����
			//ObjectManager::instantiate(new Laser(px + 29, py - 25));  //���..
			//ObjectManager::instantiate(new Laser(px + 37, py - 15));  //������

			fireTimer = 0;
		}
	}
}