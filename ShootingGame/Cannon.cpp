#include "framework.h"
#include "ShootingGame.h"

Cannon::Cannon(float px, float py) :BossSpriteChild("�����ڽ�","",true, px, py, 50, 50)
{
}

Cannon::~Cannon()
{}

void Cannon::start()
{
	setImage("Asset/����.bmp", 357, 262, 21, 22);
	addBoxCollider2D(new BoxCollider2D(3, 0, 15, 22));
}