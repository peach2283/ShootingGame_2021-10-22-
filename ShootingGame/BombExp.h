#pragma once

#include "Animation.h"

class BombExp : public Animation
{
private:
public:
	BombExp(float px, float py);
	~BombExp();

	void start();
	void onAnimationEnd();
};
