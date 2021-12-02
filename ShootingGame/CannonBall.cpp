#include "framework.h"
#include "ShootingGame.h"

CannonBall::CannonBall(float px, float py) : Sprite("","",true, px, py)
{
	this->speed = 100;
}

CannonBall::~CannonBall()
{}

void CannonBall::start()
{
	setImage("Asset/ÃÑ¾Ë2.bmp");
}

void CannonBall::update()
{}