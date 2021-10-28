#pragma once

#include "Sprite.h"

class Player : public Sprite
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
