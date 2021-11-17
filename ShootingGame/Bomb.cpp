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
		addImage("Asset/ÆÒÅÒÆøÅº2.bmp", i*34, 0, 32, 32, 0);
	}	

	//¾Ö´Ï¸ÞÀÌ¼Ç ¼Óµµ 
	setImageDelay(0.1);
}

void Bomb::update()
{
	float dist = speed * Time::deltaTime;
	translate(0, -dist);
}

void Bomb::onAnimationEnd()
{
	destroy(this);
}