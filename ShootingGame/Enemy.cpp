#include "framework.h"
#include "ShootingGame.h"

Enemy::Enemy(float px, float py) : Animation("����","",true, px, py)
{}

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
	addBoxCollider2D(new BoxCollider2D(0, 0, 190, 137));
}

void Enemy::update()
{}