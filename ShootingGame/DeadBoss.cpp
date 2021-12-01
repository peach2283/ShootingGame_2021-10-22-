#include "framework.h"
#include "ShootingGame.h"

DeadBoss::DeadBoss(float px, float py) : Sprite("","",true, px, py)
{
	this->speed = 50;
}

DeadBoss::~DeadBoss()
{}

void DeadBoss::start()
{
	//���� ���� �� �̹����� ����		
	setImage("Asset/����.bmp", 0, 613, 385, 182);

	//���� ����...�״� �ð� �����ϱ�
	destroy(this, 5);
}

void DeadBoss::update()
{
	translate(0, speed * Time::deltaTime);
}

void DeadBoss::onDestroy()
{
	cout << "---�̼� �Ϸ� / �������� Ŭ����---" << endl;
}