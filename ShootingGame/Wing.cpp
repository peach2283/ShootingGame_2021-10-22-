#include "framework.h"
#include "ShootingGame.h"

Wing::Wing(float px, float py, int num) : Sprite("보스자식","", true, px, py)
{
	this->num = num;
}

Wing::~Wing()
{}

void Wing::start()
{
	setImage("Asset/보스.bmp", imgRect[num][0], imgRect[num][1], imgRect[num][2], imgRect[num][3]);
}