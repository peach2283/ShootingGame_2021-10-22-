#include "framework.h"
#include "ShootingGame.h"

Wing::Wing(float px, float py, int num) : Sprite("","", true, px, py)
{
	this->num = num;
}

Wing::~Wing()
{}

void Wing::start()
{
	setImage("Asset/º¸½º.bmp", imgRect[num][0], imgRect[num][1], imgRect[num][2], imgRect[num][3]);
}