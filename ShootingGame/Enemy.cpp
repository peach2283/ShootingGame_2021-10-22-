#include "framework.h"
#include "ShootingGame.h"

Enemy::Enemy(float px, float py) : Animation("����","",true, px, py)
{
	this->hp = 100; //����ü��
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
			//�ɰ��� ����
			play(2);

		}else if (hp <= 0) //ü���� ��� �����Ǿ�������...�˻�
		{
			//���� ����

			//���� ����
			//destroy(this);
		}

	}
	else if (tag == "�÷��̾�")
	{
		
	}
}