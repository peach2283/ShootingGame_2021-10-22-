#pragma once

#include "BossSpriteChild.h"

class Cannon : public BossSpriteChild
{
private:
	float fireTimer;
	float fireDelay;

public:
	Cannon(float px, float py);
	~Cannon();

	void start();	
	void update();
};