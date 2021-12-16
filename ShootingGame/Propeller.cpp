#include "framework.h"
#include "ShootingGame.h"

Propeller::Propeller(float px, float py) : Animation("�����ڽ�","",true,px , py)
{
	this->hp = 100;
}

Propeller::~Propeller()
{}

void Propeller::start()
{
	//���ؾ��� �����緯 - 0 �� �ִϸ��̼�//
	addImage("Asset/����.bmp", 7 + 34 * 0, 439, 32, 12, 0);
	addImage("Asset/����.bmp", 7 + 34 * 1, 439, 32, 12, 0);

	//���⳪�� �����緯 - 1 �� �ִϸ��̼�//
	addImage("Asset/����.bmp", 7 + 34 * 0, 455, 32, 52, 1);
	addImage("Asset/����.bmp", 7 + 34 * 1, 455, 32, 52, 1);

	//�ִϸ��̼� �ӵ� ����
	setImageDelay(0.1);

	//�浹ü �߰�
	addBoxCollider2D(new BoxCollider2D(6, 0, 20, 12));
}

void Propeller::onTrigger(GameObject* other)
{
	string tag = other->getTag();

	if (tag == "������")
	{
		hp = hp - 20;

		if (0 < hp && hp <= 50)
		{
			//���ظ� ���� �ִϸ��̼����� ����
			play(1);
		}
		else if (hp <= 0)
		{
			explode();
		}
	}
	else if (tag == "��ź����")
	{
		explode();
	}
}

void Propeller::explode()
{
	//����		
	float px = getPx();
	float py = getPy();

	instantiate(new EnemyExp(px - 50, py - 50));

	//����
	destroy(this);

	//�������� ȹ��
	GameManager::addScore(25);
}