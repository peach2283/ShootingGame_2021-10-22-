#pragma once

#include "Sprite.h"

class DeadBoss : public Sprite
{
private:
	float speed;
public:
	DeadBoss(float px, float py);
	~DeadBoss();

	void start();
	void update();

	//Destroy 이벤트 오버라이딩//
	void onDestroy();
};
