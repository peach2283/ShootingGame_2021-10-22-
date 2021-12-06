#pragma once

#include "Sprite.h"

class Button : public Sprite
{
	//버튼 상태 enum//
	enum class State{normal=0, pressed=1, released=2, click=3};

private:
	State state;

public:
	Button(float px, float py);
	~Button();

	void start();
	void update();

	bool isInImageRect();

};
