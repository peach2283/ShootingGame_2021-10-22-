#include "framework.h"
#include "ShootingGame.h"

Cannon::Cannon(float px, float py) : Sprite("����ĳ��","",true, px, py)
{
	this->hp = 100;
}

Cannon::~Cannon()
{}

void Cannon::start()
{
	setImage("Asset/����.bmp", 357, 262, 21, 22);
	addBoxCollider2D(new BoxCollider2D(3, 0, 15, 22));
}

void Cannon::onTrigger(GameObject* other)
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

void Cannon::explode()
{
	//����
	float px = getPx();
	float py = getPy();

	instantiate(new EnemyExp(px - 50, py - 50));

	//����
	destroy(this);
}