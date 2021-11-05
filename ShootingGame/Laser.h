#pragma once

#include "Sprite.h"

class Laser : public Sprite
{
private:
	float speed;

public:
	Laser(float px, float py);
	~Laser();

	void start();
	void update();

	//�浹 �̺�Ʈ...�������̵�
	void onTrigger(GameObject* other);
};
