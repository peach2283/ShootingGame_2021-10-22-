#include "framework.h"
#include "ShootingGame.h"

BombItem::BombItem(float px, float py) : Sprite("폭탄아이템", "", true, px, py)
{
	this->speed = 100;

	this->moveState  = MoveState::move;
	this->blinkState = BlinkState::off;

	this->moveTimer = 2;

	this->blinkTimer = 0;
	this->blinkDelay = 0.2;
}

BombItem::~BombItem()
{}

void BombItem::start()
{
	setImage("Asset/폭탄아이템.bmp");
	addBoxCollider2D(new BoxCollider2D(0, 0, 22, 40));

	destroy(this, 5);
}

void BombItem::update()
{
	//이동 스테이트 머신
	switch (moveState)
	{
		case MoveState::move :
		{
			translate(0, speed * Time::deltaTime);

			moveTimer = moveTimer - Time::deltaTime;

			if (moveTimer <= 0)
			{
				moveState = MoveState::stop;
			}

		}
		break;
		
		case MoveState::stop:
		{
		     //깜빡임 서브 스테이트 머신
			 switch (blinkState)
			 {
				case BlinkState::on:
				{
					setActive(true);

					blinkTimer = blinkTimer + Time::deltaTime;

					if (blinkTimer >= blinkDelay)
					{
						blinkState = BlinkState::off;
						blinkTimer = 0;
					}

				}
				break;
			
				case BlinkState::off:
				{
					setActive(false);

					blinkTimer = blinkTimer + Time::deltaTime;

					if (blinkTimer >= blinkDelay)
					{
						blinkState = BlinkState::on;
						blinkTimer = 0;
					}
				
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