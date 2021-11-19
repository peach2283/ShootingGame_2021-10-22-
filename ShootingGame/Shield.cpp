#include "framework.h"
#include "ShootingGame.h"

Shield::Shield(float px, float py) : Animation("", "", true, px, py)
{}

Shield::~Shield()
{}

void Shield::start()
{
	addImage("Asset/��ȣ����1.bmp", 0);
	addImage("Asset/��ȣ����2.bmp", 0);
	addImage("Asset/��ȣ����3.bmp", 0);
}