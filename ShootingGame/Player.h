#pragma once

#include "Animation.h"

class Player : public Animation
{
private:

	float speed;

	float fireTimer; //�߻�ð� ����
	float fireDelay; //�߻簣 ���� �ð�

public:
	Player(float px, float py);
	~Player();

	void start();
	void update();

	void move();  //�̵� �Լ�
	void fire();  //�߻� �Լ�
};
