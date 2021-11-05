#pragma once

#include "Animation.h"

class Enemy : public Animation
{
private:
	
	float hp; //���� ü��

public:
	Enemy(float px, float py);
	~Enemy();

	void start();
	void update();

	//�浹�̺�Ʈ..�������̵�
	void onTrigger(GameObject * other);
};
