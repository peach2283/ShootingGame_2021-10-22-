#include "framework.h"
#include "ShootingGame.h"

Player::Player(float px, float py) : Animation("�÷��̾�","", true, px, py)
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
	//�ִϸ��̼�...�̹��� �߰��ϱ�//	
	//���..�̵����� �ʴ� �ִϸ��̼� - 0 ��//
	addImage("Asset/�����̵�2.bmp", 192, 0, 62, 80, 0);

	//������..�̵� �ִϸ��̼� - 1 ��//
	addImage("Asset/�����̵�2.bmp", 192 + 64 * 0, 0, 62, 80, 1);
	addImage("Asset/�����̵�2.bmp", 192 + 64 * 1, 0, 62, 80, 1);
	addImage("Asset/�����̵�2.bmp", 192 + 64 * 2, 0, 62, 80, 1);
	addImage("Asset/�����̵�2.bmp", 192 + 64 * 3, 0, 62, 80, 1);

	//����...�̵� �ִϸ��̼� - 2��
	addImage("Asset/�����̵�2.bmp", 192 - 64 * 0, 0, 62, 80, 2);
	addImage("Asset/�����̵�2.bmp", 192 - 64 * 1, 0, 62, 80, 2);
	addImage("Asset/�����̵�2.bmp", 192 - 64 * 2, 0, 62, 80, 2);
	addImage("Asset/�����̵�2.bmp", 192 - 64 * 3, 0, 62, 80, 2);

	//�ִϸ��̼�..��Ǫ(loop) �ɼ� ����//
	setLoop(false);

	//�ִϸ��̼�..�̹��� ������ �ɼ� ����//
	setImageDelay(0.1);

	//�浹ü �߰��ϱ�//
	addBoxCollider2D(new BoxCollider2D(24, 5,  14, 65));
	addBoxCollider2D(new BoxCollider2D(5 , 42, 52, 15));

	//���� �ڽİ�ü �߰��ϱ�
	addChildObject(new Shield(-12, -10), 2);
}

void Player::update()
{
	switch (state)
	{
		case State::up  :  //�÷��̾� ���� ����
		{
			float dist = speed * Time::deltaTime;
			translate(0, -dist);

			float py = getPy();

			if (py <= HEIGHT - 150)
			{
				state = State::control;              //control ��������
				 
				/************���� �����******************/
				//GameObject* shield = find("����");    //�����ڽİ�ü ã��

				//if (shield != nullptr)
				//{
				//	shield->setActive(false);             //�����ڽİ�ü..��Ȱ��ȭ�ϱ�  
				//}
				//else {
				//	cout << "���� �ڽİ�ü�� ã���� ����" << endl;
				//}

				/**************��������******************/
				GameObject * shield=find("����");

				if (shield != nullptr)
				{
					destroy(shield);
				}
				else {
					cout << "���� �ڽİ�ü�� ã�� �� ����" << endl;
				}
			}
		}
		break;

		case State::control : //�÷��̾� Ű�Է� ��Ʈ�� ����
		{
			move();
			fire();
		}
		break;
	}

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

		//�ִϸ��̼�..�����ϱ�
		play(2);

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

	//�¿�..�̵�Ű �Է��� ������...
	if (Input::getKey(KeyCode::leftArrow) != true && Input::getKey(KeyCode::rightArrow) != true)
	{
		//�ִϸ��̼� �����ϱ�
		play(0);
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

			if (fireCount == 1)
			{
				///�ѹ� �߻��ϱ�//
				instantiate(new Laser(px + 29, py - 20));
			}
			else if (fireCount == 2)
			{
				///�ι� �߻��ϱ�//
				instantiate(new Laser(px + 24, py - 20));
				instantiate(new Laser(px + 34, py - 20));
			}
			else if (fireCount == 3)
			{
				//���� �߻��ϱ�//
				instantiate(new Laser(px + 21, py - 15));  //����
				instantiate(new Laser(px + 29, py - 25));  //���..
				instantiate(new Laser(px + 37, py - 15));  //������
			}

			fireTimer = 0;
		}
	}

	//��ź �߻��ϱ�
	if (Input::getKeyDown(KeyCode::Z) == true)
	{
		if (bombCount > 0)
		{
			float px = getPx();
			float py = getPy();

			instantiate(new Bomb(px + 15, py - 15));

			bombCount--; //��ź���� ����
		}
		else {
			cout << "���� ��ź�� �����ϴ�." << endl;
		}
	}

}

void Player::onTrigger(GameObject* other)
{
	string tag = other->getTag();

	if (tag == "�����Ѿ�") 
	{
		damage(10);
	}
	else if (tag == "����")
	{
		damage(50);
	}
	else if (tag == "����")
	{
		damage(100);
	}
	else if (tag == "�Ѿ˾�����")  //�÷��̾� �������߻� ���� ���� ������
	{
		if (fireCount < 3)
		{
			fireCount++;
		}
	}
	else if (tag == "��ź������") //�÷��̾� ��ź���� ���� ������
	{
		bombCount++;  //��ź �ִ밹���� ���߿� �����
	}
}

void Player::damage(float amount)
{
	hp = hp - amount;

	if (hp <= 0)
	{
		//�÷��̾� ����//
		float px = getPx();
		float py = getPy();

		instantiate(new PlayerExp(px - 33, py - 27));

		//�÷��̾� ����//
		destroy(this);

		//�÷��̾� ������ �õ��ϱ�
		GameManager::reSpawnPlayer();
	}
}