#include "framework.h"
#include "ShootingGame.h"

BulletItem::BulletItem(float px, float py) : Sprite("총알아이템", "", true, px, py)
{}

BulletItem::~BulletItem()
{}

void BulletItem::start()
{
	setImage("Asset/총알아이템.bmp");
	addBoxCollider2D(new BoxCollider2D(0, 0, 25, 80));
}

void BulletItem::onTrigger(GameObject* other)
{
	string tag = other->getTag();

	if (tag == "플레이어")
	{
		destroy(this); //아이템 제거하기
	}
}