#pragma once

#include "Animation.h"

class Enemy : public Animation
{
	enum class State { down = 0, left = 1, right = 2, fall = 3 };

private:
	
	float hp;		 //적기 체력
	float speed;     //이동 속력
	float fallSpeed; //추락 속력

	State state;	//상태(State) 변수

	float fireTimer;
	float fireDelay;

	int downStopVar;     //down 상태에서 left상태로..전이되는 높이 변화랜덤값
	int num;             //적기 생성 번호

	bool isItemDropped;  //아이템을 생성했는지..정보표시변수

public:

	Enemy(float px, float py, int num);
	~Enemy();

	void start();
	void update();

	//충돌이벤트..오버라이딩
	void onTrigger(GameObject * other);

	//제거이벤트..오버라이딩
	void onDestroy();

	//적기 폭발 함수
	void explode();
};
