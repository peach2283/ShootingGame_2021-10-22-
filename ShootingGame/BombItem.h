#pragma once

#include "Sprite.h"

class BombItem : public Sprite
{
	enum class MoveState  { move, stop };  //�̵�/���� ������Ʈ�ӽ�
	enum class BlinkState { on, off   };   //���̱�/����� ������Ʈ �ӽ�

private:
	float speed;

	MoveState  moveState;
	BlinkState blinkState;

	float moveTimer;

	float blinkTimer;
	float blinkDelay;

public:
	BombItem(float px, float py);
	~BombItem();

	void start();
	void update();

	void onTrigger(GameObject* other);
};
