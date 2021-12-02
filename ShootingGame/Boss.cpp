#include "framework.h"
#include "ShootingGame.h"

Boss::Boss(float px, float py) : Sprite("����","",true, px, py)
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
	//���� �⺻�̹��� �ε� �ϱ�//
	setImage("Asset/����.bmp", 0, 0, 493, 206);

	//�����緯..�ڽİ�ü �߰��ϱ�//
	addChildObject(new Propeller( 63, 41));
	addChildObject(new Propeller(111, 41));
	addChildObject(new Propeller(159, 41));

	addChildObject(new Propeller(302, 41));
	addChildObject(new Propeller(350, 41));
	addChildObject(new Propeller(398, 41));

	//���� �ڽİ�ü �߰��ϱ�//
	addChildObject(new Wing(256, 97 , 0 )); //������ ù��°
	addChildObject(new Wing(302, 94,  1 )); //������ �ι�°
	addChildObject(new Wing(350, 90,  2 )); //������ ����°
	addChildObject(new Wing(405, 84,  3 )); //������ �׹�°

	addChildObject(new Wing(206, 98,  4 )); //���� ù��°
	addChildObject(new Wing(158, 94,  5 )); //���� �ι�°
	addChildObject(new Wing(110, 90,  6 )); //���� ����°
	addChildObject(new Wing(62 , 84,  7 )); //���� �׹�°

	//���� �� �ڽİ�ü �߰��ϱ�//
	addChildObject(new Gun(94 , 71, "��0"));
	addChildObject(new Gun(142, 71, "��1"));
	addChildObject(new Gun(190, 71, "��2"));

	addChildObject(new Gun(238, 63 , "��3"));

	addChildObject(new Gun(286, 71, "��4"));
	addChildObject(new Gun(334, 71, "��5"));
	addChildObject(new Gun(382, 71, "��6"));

	//���� ���� �ڽİ�ü �߰��ϱ�
	addChildObject(new Cannon(265 + 5, 97 + 10));
	addChildObject(new Cannon(206 - 5, 97 + 10));

	//���� ���̴� �ڽİ�ü �߰��ϱ�
	addChildObject(new Radar(241, 105));
	addChildObject(new Radar(241, 117));

	//���� ��ü �浹ü �߰��ϱ�
	addBoxCollider2D(new BoxCollider2D(230,    5,   33,     170)); //��� ����
	addBoxCollider2D(new BoxCollider2D(0,     60,   493,    45));  //��� ����
	addBoxCollider2D(new BoxCollider2D(185,   175,  123,    25));  //����  ����
}

void Boss::update()
{
	//���� ������Ʈ �ӽ�//
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
				/**************������ �߻��ϱ�*********************/
				string gunName[7] = { "��0", "��1","��2", "��3", "��4", "��5", "��6" };

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

	//���� �ڽİ��� �˾ƿͼ�..���� ���� ��Ű��//
	int count = childCount();

	if (count == 0)
	{
		float px = getPx();
		float py = getPy();

		//���� ���� ȿ��
		instantiate(new EnemyExp(px + 180, py + 40), 1);

		instantiate(new EnemyExp(px + 180 + 70,  py + 40), 1);
		instantiate(new EnemyExp(px + 180 + 140, py + 40), 1);
		instantiate(new EnemyExp(px + 180 + 210, py + 40), 1);

		instantiate(new EnemyExp(px + 180 - 70,  py + 40), 1);
		instantiate(new EnemyExp(px + 180 - 140, py + 40), 1);
		instantiate(new EnemyExp(px + 180 - 210, py + 40), 1);

		instantiate(new EnemyExp(px + 180, py + 40 - 70), 1);
		instantiate(new EnemyExp(px + 180, py + 40 + 70), 1);

		//���� ��ü�� ����
		destroy(this);

		//�ı��� ���� ��ü��...���ŵ� ���� ��ġ�� ������
		instantiate(new DeadBoss(px + 45, py+10));
	}	
}