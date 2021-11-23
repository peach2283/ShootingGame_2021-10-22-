#include "framework.h"
#include "ShootingGame.h"

BulletItem::BulletItem(float px, float py) : Sprite("�Ѿ˾�����", "", true, px, py)
{}

BulletItem::~BulletItem()
{}

void BulletItem::start()
{
	setImage("Asset/�Ѿ˾�����.bmp");
	addBoxCollider2D(new BoxCollider2D(0, 0, 25, 80));
}

void BulletItem::onTrigger(GameObject* other)
{
	string tag = other->getTag();

	if (tag == "�÷��̾�")
	{
		destroy(this); //������ �����ϱ�
	}
}