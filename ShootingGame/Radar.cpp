#include "framework.h"
#include "ShootingGame.h"

Radar::Radar(float px, float py) : BossSpriteChild("보스자식","", true, px, py, 60, 50)
{}

Radar::~Radar()
{}

void Radar::start()
{
	setImage("Asset/보스.bmp", 360, 245, 11, 9);
	addBoxCollider2D(new BoxCollider2D(0, 0, 11, 9));
}