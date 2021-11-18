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
		addImage("Asset/埔乓气藕2.bmp", i*34, 0, 32, 32, 0);
	}	

	//局聪皋捞记 加档 
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

	destroy(this);					          //气藕 力芭
	instantiate(new BombExp(px-52, py-52));   //气藕捞 气惯
}