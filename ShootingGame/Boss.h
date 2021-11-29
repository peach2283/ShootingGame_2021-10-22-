#pragma once

#include "Sprite.h"

class Boss : public Sprite
{
	enum class State{down=0 , attack=1};

private:
	float speed;
	State state;

public:
	Boss(float px, float py);
	~Boss();

	void start();
	void update();
};
