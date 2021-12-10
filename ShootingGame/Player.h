#pragma once

#include "Animation.h"

class Player : public Animation
{
	enum class State{up = 0, control = 1};

private:

	float speed;

	float fireTimer; //�߻�ð� ����
	float fireDelay; //�߻簣 ���� �ð�
	
	int   fireCount; //������ �߻簹��
	State state;

public:
	Player(float px, float py);
	~Player();

	void start();
	void update();

	void move();  //�̵� �Լ�
	void fire();  //�߻� �Լ�

	void onTrigger(GameObject* other);
	void damage(float amount);
};
