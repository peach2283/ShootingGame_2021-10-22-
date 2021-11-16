#include "framework.h"
#include "ShootingGame.h"

EnemyBullet::EnemyBullet(float px, float py) : Sprite("�����Ѿ�", "", true, px, py)
{
	this->speed = 250;
}

EnemyBullet::~EnemyBullet()
{}

void EnemyBullet::start()
{
	setImage("Asset/�Ѿ�1.bmp");
	addBoxCollider2D(new BoxCollider2D(0, 0, 16, 15));

	//���� �Ѿ� ������Ÿ��//
	destroy(this, 10);
}

void EnemyBullet::update()
{
	float dist = speed * Time::deltaTime;
	translate(0, dist);
}

void EnemyBullet::onTrigger(GameObject* other)
{
	string tag = other->getTag();

	if (tag == "�÷��̾�")
	{
		//���� �Ѿ� ����//
		float px = getPx();
		float py = getPy();

		instantiate(new BulletExp(px-5, py-5));

		//���� �Ѿ� ����//
		destroy(this);
	}
}