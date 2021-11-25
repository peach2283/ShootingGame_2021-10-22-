#include "framework.h"
#include "ShootingGame.h"

BombItem::BombItem(float px, float py) : Sprite("폭탄아이템", "", true, px, py)
{
	this->speed = 100;

	this->moveState  = MoveState::move;
	this->blinkState = BlinkState::off;
}

BombItem::~BombItem()
{}

void BombItem::start()
{
	setImage("Asset/폭탄아이템.bmp");
	addBoxCollider2D(new BoxCollider2D(0, 0, 22, 40));
}

void BombItem::update()
{
	//이동 스테이트 머신
	switch (moveState)
	{
		case MoveState::move :
		{
		
		}
		break;

		
		case MoveState::stop:
		{
		     //깜빡임 서브 스테이트 머신
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

	if (tag == "플레이어")
	{
		destroy(this);
	}
}