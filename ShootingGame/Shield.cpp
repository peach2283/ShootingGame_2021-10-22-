#include "framework.h"
#include "ShootingGame.h"

Shield::Shield(float px, float py) : Animation("����", "����", true , px, py)
{
	this->activeTimer = 5;
}

Shield::~Shield()
{}

void Shield::start()
{
	//���� �ִϸ��̼� �̹��� �߰�
	addImage("Asset/��ȣ����1.bmp", 0);
	addImage("Asset/��ȣ����2.bmp", 0);
	addImage("Asset/��ȣ����3.bmp", 0);

	//�浹ü �߰�
	addBoxCollider2D(new BoxCollider2D(0, 0, 90, 90));
}

void Shield::update()
{
	/**
	activeTimer = activeTimer - Time::deltaTime;

	if (activeTimer <= 0)
	{
		//���� ��Ȱ��ȭ �ϱ�
		setActive(false);
	}
	**/
}