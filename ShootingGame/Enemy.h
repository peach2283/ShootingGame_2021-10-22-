#pragma once

#include "Animation.h"

class Enemy : public Animation
{
private:
public:
	Enemy(float px, float py);
	~Enemy();

	void start();
	void update();
};
