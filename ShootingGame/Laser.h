#pragma once

#include "Sprite.h"

class Laser : public Sprite
{
private:
	float speed;

public:
	Laser(float px, float py);
	~Laser();

	void start();
	void update();

	//충돌 이벤트...오버라이딩
	void onTrigger(GameObject* other);
};
