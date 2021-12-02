#pragma once

#include "BossSpriteChild.h"

class Gun : public BossSpriteChild
{
private:
public:
	Gun(float px, float py, string name);
	~Gun();

	void start();
	void fire();
};
