#pragma once

#include "Sprite.h"

class BombItem : public Sprite
{
	enum MoveState  { move, stop };  //이동/정지 스테이트머신
	enum BlinkState { on, off   };   //보이기/숨기기 스테이트 머신

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
