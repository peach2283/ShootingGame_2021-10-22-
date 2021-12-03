#include "framework.h"
#include "ShootingGame.h"

CannonBall::CannonBall(float px, float py, float angle) : Sprite("","",true, px, py)
{
	this->speed = 100;
	this->angle = angle;
}

CannonBall::~CannonBall()
{}

void CannonBall::start()
{
	setImage("Asset/�Ѿ�2.bmp");
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