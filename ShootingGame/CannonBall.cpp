#include "framework.h"
#include "ShootingGame.h"

CannonBall::CannonBall(float px, float py, float angle) : Sprite("������ź","",true, px, py)
{
	this->speed = 100;
	this->angle = angle;
}

CannonBall::~CannonBall()
{}

void CannonBall::start()
{
	setImage("Asset/�Ѿ�2.bmp");
	addBoxCollider2D(new BoxCollider2D(0, 0, 17, 17));

	destroy(this, 10);
}

void CannonBall::update()
{
	//x�� ���� ����
	float nx=1, ny=0;

	//���� ���� ȸ����Ű��
	float theta = angle*M_PI/180;

	float x = nx * cos(theta) * speed * Time::deltaTime;
	float y = nx * sin(theta) * speed * Time::deltaTime;

	//���⺤�ͷ�..�̵�
	translate(x, y);
}

void CannonBall::onTrigger(GameObject* other)
{
	string tag = other->getTag();

	if (tag == "�÷��̾�" || tag == "��ź����" || tag == "����")
	{
		//���� �Ѿ� ����//
		float px = getPx();
		float py = getPy();

		instantiate(new BulletExp(px - 5, py - 5));

		//���� �Ѿ� ����//
		destroy(this);
	}
}