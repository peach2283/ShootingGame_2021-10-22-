#pragma once

#include "Animation.h"

class Bomb : public Animation
{
private:
	float speed;

public:
	Bomb(float px, float py);
	~Bomb();

	void start();
	void update();

	void onAnimationEnd();
};
