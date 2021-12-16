#include "framework.h"
#include "ShootingGame.h"

BossSpriteChild::BossSpriteChild(string tag, string name, bool active, float px, float py, float ex, float ey)
				:Sprite(tag, name, active, px, py)
{
	this->hp = 100;
	this->ex = ex;
	this->ey = ey;
}

BossSpriteChild::~BossSpriteChild()
{}

void BossSpriteChild::onTrigger(GameObject* other)
{
	string tag = other->getTag();

	if (tag == "������")
	{
		//ü���� ����//
		hp = hp - 20;

		//ü���� ��� �����ϸ�..����/����//
		if (hp <= 0)
		{
			explode();
		}
	}
	else if (tag == "��ź����")
	{
		explode();
	}
}

void BossSpriteChild::explode()
{
	//����
	float px = getPx();
	float py = getPy();

	instantiate(new EnemyExp(px - ex, py - ey));

	//����
	destroy(this);

	//�������� ȹ��
	GameManager::addScore(25);
}