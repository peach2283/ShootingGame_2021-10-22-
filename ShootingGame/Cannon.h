#pragma once

#include "BossSpriteChild.h"

class Cannon : public BossSpriteChild
{
private:
	

public:
	Cannon(float px, float py);
	~Cannon();

	void start();	
};