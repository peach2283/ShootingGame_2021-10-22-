#pragma once

#include "Sprite.h"

class CannonBall : public Sprite
{
private:
	float speed;
	float angle;

public:
	CannonBall(float px, float py, float angle);
	~CannonBall();

	void start();
	void update();

	void onTrigger(GameObject* other);
};
