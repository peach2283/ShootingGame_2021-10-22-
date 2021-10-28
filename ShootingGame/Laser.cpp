#include "framework.h"
#include "ShootingGame.h"

Laser::Laser(float px, float py) : Sprite("","", true, px, py)
{
	this->speed = 250;
}

Laser::~Laser()
{}

void Laser::start()
{
	setImage("Asset/·¹ÀÌÀú.bmp");
}

void Laser::update()
{
	float dist = speed * Time::deltaTime;
	translate(0, -dist);
}