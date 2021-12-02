#pragma once

#include "Sprite.h"

#define MAX_FIRE_LINE 15

class Boss : public Sprite
{
	enum class State{down=0 , attack=1};

private:
	float speed;
	State state;

	float fireTimer;
	float fireDelay;

	bool  fireArray[MAX_FIRE_LINE][7] = {
								{true, true, true,       false,     false, false, false},
								{true, true, true,       false,     false, false, false},
								{true, true, true,       false,     false, false, false},
								{true, true, true,       false,     false, false, false},
								{true, true, true,       false,     false, false, false},

								{false, false, false,    false,     true, true, true},
								{false, false, false,    false,     true, true, true},
								{false, false, false,    false,     true, true, true},
								{false, false, false,    false,     true, true, true},
								{false, false, false,    false,     true, true, true},

								{false, false, false,    true,     false, false, false,},
								{false, false, false,    true,     false, false, false,},
								{false, false, false,    true,     false, false, false,},
								{false, false, false,    true,     false, false, false,},
								{false, false, false,    true,     false, false, false,}
							};
	int fireIndex;

public:
	Boss(float px, float py);
	~Boss();

	void start();
	void update();
};
