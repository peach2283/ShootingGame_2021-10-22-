#pragma once

#include "Animation.h"

class Enemy : public Animation
{
private:
	
	float hp; //적기 체력

public:
	Enemy(float px, float py);
	~Enemy();

	void start();
	void update();

	//충돌이벤트..오버라이딩
	void onTrigger(GameObject * other);
};
