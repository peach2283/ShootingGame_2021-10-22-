#pragma once

#include "Sprite.h"

class DeadBoss : public Sprite
{
private:
	float speed;
public:
	DeadBoss(float px, float py);
	~DeadBoss();

	void start();
	
};
