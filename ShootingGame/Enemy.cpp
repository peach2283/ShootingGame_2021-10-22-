#include "framework.h"
#include "ShootingGame.h"

Enemy::Enemy(float px, float py) : Animation("����","",true, px, py)
{
	this->hp    = 100; //����ü��
	
	this->speed		= 100;
	this->fallSpeed = 200;

	this->state = State::down;
	
	this->fireTimer = 0;
	this->fireDelay = 1;

	this->downStopVar = Random::range(-80, 80);
}

Enemy::~Enemy()
{}

void Enemy::start()
{
	//�ִϸ��̼� �̹�����..�ε��ϱ�//
	//���ذ� ���� ���� �ִϸ��̼� Ŭ�� - 0 �� Ŭ��//
	for (int i = 0; i < 2; i++)
	{
		addImage("Asset/����.bmp", 1 + 200 * i, 281, 190, 137, 0);  //i�� �̹���
	}

	//�߰� ���ظ� ���� ���� �ִϸ��̼� Ŭ�� - 1 �� Ŭ�� //
	for (int i = 0; i < 4; i++)
	{
		addImage("Asset/����.bmp", 1 + 200 * i, 141, 190, 137, 1);  //i�� �̹���	
	}

	//�ɰ��� ���ظ� ���� ���� �ִϸ��̼� Ŭ�� - 2 �� Ŭ��//
	for (int i = 0; i < 4; i++)
	{
		addImage("Asset/����.bmp", 1 + 200 * i, 1, 190, 137, 2);  //i�� �̹���
	}

	//�浹ü �߰��ϱ�
	addBoxCollider2D(new BoxCollider2D(0,  80, 190,  25));
	addBoxCollider2D(new BoxCollider2D(88, 25 , 14, 110));
	addBoxCollider2D(new BoxCollider2D(60, 10  , 70, 15));
}

void Enemy::update()
{
	/////////////�̵�/�߶� ������Ʈ�ӽ�///////
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

	///////////�Ѿ˹߻�//////////////
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
	
	if (tag == "������")
	{
		//ü�°���
		hp = hp - 10;
	
		if (70 <= hp && hp <= 100)
		{
			//���ؾ���
			play(0);
		}
		else if (40 <= hp && hp < 70)
		{
			//���� ����
			play(1);
		}
		else if (0 < hp && hp < 40)
		{
			//�ɰ��� ����..�ִϸ��̼����� ����
			play(2);

			if (state != State::fall)
			{
				//�߶����·�..�����ϱ�
				state = State::fall;

				//�߶��� ���ߵ��� �ʰ�..ȭ��Ʒ���..������� ���.. destroy�ϱ�
				destroy(this, 5);
			}

		}else if (hp <= 0) //ü���� ��� �����Ǿ�������...�˻�
		{				
			explode();
		}

	}
	else if (tag == "�÷��̾�")
	{
		explode();
	}
}

void Enemy::explode()
{
	//������ġ
	float px = getPx();
	float py = getPy();

	//���� ����
	instantiate(new EnemyExp(px + 30, py + 30));

	//���� ����
	destroy(this);
}

void Enemy::onDestroy()
{
	//�������� ī��Ʈ ����
	GameManager::addEnemyDestroyCount();
}