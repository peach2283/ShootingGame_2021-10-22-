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
	if (num == 0)
	{
		setImage("Asset/����.bmp", 298, 425, 30, 18);
	}
	else if (num == 1)
	{
		setImage("Asset/����.bmp", 329, 426, 32, 16);
	}
	else if (num == 2)
	{
		setImage("Asset/����.bmp", 364, 426, 32, 16);
	}
	else if (num == 3)
	{
		setImage("Asset/����.bmp", 399, 426, 32, 16);
	}
}