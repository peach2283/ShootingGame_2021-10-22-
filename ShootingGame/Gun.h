#pragma once

#include "BossSpriteChild.h"

class Gun : public BossSpriteChild
{
private:
public:
	Gun(float px, float py);
	~Gun();

	void start();
};
