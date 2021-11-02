#pragma once

#include "Animation.h"

class Player : public Animation
{
private:

	float speed;

	float fireTimer; //발사시간 측정
	float fireDelay; //발사간 지연 시간

public:
	Player(float px, float py);
	~Player();

	void start();
	void update();

	void move();  //이동 함수
	void fire();  //발사 함수
};
