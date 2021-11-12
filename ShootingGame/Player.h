#pragma once

#include "Animation.h"

class Player : public Animation
{
private:

	float speed;

	float fireTimer; //�߻�ð� ����
	float fireDelay; //�߻簣 ���� �ð�

	float hp;   //���Ŀ�..���ӸŴ�����..�̵�

public:
	Player(float px, float py);
	~Player();

	void start();
	void update();

	void move();  //�̵� �Լ�
	void fire();  //�߻� �Լ�

	void onTrigger(GameObject* other);
};
