#include "framework.h"
#include "ShootingGame.h"

Laser::Laser(float px, float py) : Sprite("������","", true, px, py)
{
	this->speed = 250;
}

Laser::~Laser()
{}

void Laser::start()
{
	setImage("Asset/������.bmp");

	//�浹ü �߰�
	addBoxCollider2D(new BoxCollider2D(0, 0, 6, 33));
}

void Laser::update()
{
	float dist = speed * Time::deltaTime;
	translate(0, -dist);
}