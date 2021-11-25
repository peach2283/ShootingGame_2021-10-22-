#include "framework.h"
#include "ShootingGame.h"

BombItem::BombItem(float px, float py) : Sprite("��ź������", "", true, px, py)
{
	this->speed = 100;

	this->moveState  = MoveState::move;
	this->blinkState = BlinkState::off;
}

BombItem::~BombItem()
{}

void BombItem::start()
{
	setImage("Asset/��ź������.bmp");
	addBoxCollider2D(new BoxCollider2D(0, 0, 22, 40));
}

void BombItem::update()
{
	//�̵� ������Ʈ �ӽ�
	switch (moveState)
	{
		case MoveState::move :
		{
		
		}
		break;

		
		case MoveState::stop:
		{
		     //������ ���� ������Ʈ �ӽ�
			 switch (blinkState)
			 {
				case BlinkState::on:
				{
				
				}
				break;
			
				case BlinkState::off:
				{
				
				
				}
				break;
			
			}
		
		}
		break;
	}	
}

void BombItem::onTrigger(GameObject* other)
{
	string tag = other->getTag();

	if (tag == "�÷��̾�")
	{
		destroy(this);
	}
}