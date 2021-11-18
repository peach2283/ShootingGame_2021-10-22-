#include "framework.h"
#include "ShootingGame.h"

Bomb::Bomb(float px, float py) : Animation("", "", true, px, py)
{
	this->speed = 100;
}

Bomb::~Bomb()
{}

void Bomb::start()
{
	for (int i = 0; i < 8; i++)
	{
		addImage("Asset/������ź2.bmp", i*34, 0, 32, 32, 0);
	}	

	//�ִϸ��̼� �ӵ� 
	setImageDelay(0.1);
}

void Bomb::update()
{
	float dist = speed * Time::deltaTime;
	translate(0, -dist);
}

void Bomb::onAnimationEnd()
{
	float px = getPx();
	float py = getPy();

	destroy(this);					          //��ź ����
	instantiate(new BombExp(px-52, py-52));   //��ź�� ����
}