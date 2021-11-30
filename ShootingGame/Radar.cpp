#include "framework.h"
#include "ShootingGame.h"

Radar::Radar(float px, float py) : BossSpriteChild("�����ڽ�","", true, px, py, 60, 50)
{}

Radar::~Radar()
{}

void Radar::start()
{
	setImage("Asset/����.bmp", 360, 245, 11, 9);
	addBoxCollider2D(new BoxCollider2D(0, 0, 11, 9));
}