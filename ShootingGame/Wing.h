#pragma once

#include "Sprite.h"

class Wing : public Sprite
{
private:
	int num;

public:
	Wing(float px, float py, int num);
	~Wing();

	void start();
};
