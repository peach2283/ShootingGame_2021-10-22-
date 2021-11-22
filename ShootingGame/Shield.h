#pragma once

#include "Animation.h"

class Shield : public Animation
{
private:

	float activeTimer;

public:
	Shield(float px, float py);
	~Shield();

	void start();
	void update();
};
