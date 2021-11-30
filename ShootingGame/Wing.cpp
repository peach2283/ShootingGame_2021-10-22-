#include "framework.h"
#include "ShootingGame.h"

Wing::Wing(float px, float py, int num) : BossSpriteChild("보스자식","", true, px, py, 50, 50)
{
	this->num = num;
}

Wing::~Wing()
{}

void Wing::start()
{
	setImage("Asset/보스.bmp", imgRect[num][0], imgRect[num][1], imgRect[num][2], imgRect[num][3]);
	addBoxCollider2D(new BoxCollider2D(0, 0, imgRect[num][2], imgRect[num][3]));
}