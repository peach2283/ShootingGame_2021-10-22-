#pragma once

#include "Sprite.h"

class CannonBall : public Sprite
{
private:
	float speed;

public:
	CannonBall(float px, float py);
	~CannonBall();

	void start();
	void update();
};
