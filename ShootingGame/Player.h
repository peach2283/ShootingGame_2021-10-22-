#pragma once

#include "Animation.h"

class Player : public Animation
{
	enum class State{up = 0, control = 1};

private:

	float speed;

	float fireTimer; //발사시간 측정
	float fireDelay; //발사간 지연 시간

	float hp;   //이후에..게임매니저로..이동

	State state;

public:
	Player(float px, float py);
	~Player();

	void start();
	void update();

	void move();  //이동 함수
	void fire();  //발사 함수

	void onTrigger(GameObject* other);

	void damage(float amount);
};
