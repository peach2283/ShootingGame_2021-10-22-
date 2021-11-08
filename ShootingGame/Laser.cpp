#include "framework.h"
#include "ShootingGame.h"

Laser::Laser(float px, float py) : Sprite("레이저","", true, px, py)
{
	this->speed = 250;
}

Laser::~Laser()
{}

void Laser::start()
{
	setImage("Asset/레이저.bmp");

	//충돌체 추가
	addBoxCollider2D(new BoxCollider2D(0, 0, 6, 33));
}

void Laser::update()
{
	float dist = speed * Time::deltaTime;
	translate(0, -dist);
}

void Laser::onTrigger(GameObject* other)
{
	string tag = other->getTag();

	if (tag == "적기")
	{
		//폭발

		//제거
		destroy(this);
	}
}