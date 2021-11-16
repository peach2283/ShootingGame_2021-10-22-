#pragma once

#include "Animation.h"

class Enemy : public Animation
{
	enum class State { down = 0, left = 1, right = 2, fall = 3 };

private:
	
	float hp;    //���� ü��
	float speed;     //�̵� �ӷ�
	float fallSpeed; //�߶� �ӷ�

	State state; //����(State) ����

	float fireTimer;
	float fireDelay;

	int downStopVar;  //down ���¿��� left���·�..���̵Ǵ� ���� ��ȭ������

public:

	Enemy(float px, float py);
	~Enemy();

	void start();
	void update();

	//�浹�̺�Ʈ..�������̵�
	void onTrigger(GameObject * other);

	//�����̺�Ʈ..�������̵�
	void onDestroy();

	//���� ���� �Լ�
	void explode();
};
