#pragma once

#include "Sprite.h"

class Boss : public Sprite
{
	enum class State{down=0 , attack=1};

private:
	float speed;
	State state;

	float fireTimer;
	float fireDelay;

	bool  fireArray[10][7] = { 
								{true, true, true,       false,     false, false, false},
								{true, true, true,       false,     false, false, false},
								{true, true, true,       false,     false, false, false},
								{true, true, true,       false,     false, false, false},
								{true, true, true,       false,     false, false, false},

								{false, false, false,    false,     true, true, true},
								{false, false, false,    false,     true, true, true},
								{false, false, false,    false,     true, true, true},
								{false, false, false,    false,     true, true, true},
								{false, false, false,    false,     true, true, true}
							};
	int fireIndex;

public:
	Boss(float px, float py);
	~Boss();

	void start();
	void update();
};
