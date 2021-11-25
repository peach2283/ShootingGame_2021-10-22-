#include "framework.h"
#include "ShootingGame.h"

BombItem::BombItem(float px, float py) : Sprite("��ź������", "", true, px, py)
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
	setImage("Asset/��ź������.bmp");
	addBoxCollider2D(new BoxCollider2D(0, 0, 22, 40));

	destroy(this, 5);
}

void BombItem::update()
{
	//�̵� ������Ʈ �ӽ�
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
		     //������ ���� ������Ʈ �ӽ�
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

	if (tag == "�÷��̾�")
	{
		destroy(this);
	}
}