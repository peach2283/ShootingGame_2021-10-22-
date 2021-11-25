#pragma once

#include "Sprite.h"

class BombItem : public Sprite
{
	enum MoveState  { move, stop };  //�̵�/���� ������Ʈ�ӽ�
	enum BlinkState { on, off   };   //���̱�/����� ������Ʈ �ӽ�

private:
	float speed;

	MoveState  moveState;
	BlinkState blinkState;

public:
	BombItem(float px, float py);
	~BombItem();

	void start();
	void update();

	void onTrigger(GameObject* other);
};
