#include "framework.h"
#include "ShootingGame.h"

Wing::Wing(float px, float py, int num) : BossSpriteChild("�����ڽ�","", true, px, py, 50, 50)
{
	this->num = num;
}

Wing::~Wing()
{}

void Wing::start()
{
	setImage("Asset/����.bmp", imgRect[num][0], imgRect[num][1], imgRect[num][2], imgRect[num][3]);
	addBoxCollider2D(new BoxCollider2D(0, 0, imgRect[num][2], imgRect[num][3]));
}