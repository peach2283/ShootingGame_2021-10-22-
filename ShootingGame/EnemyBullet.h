#pragma once

#include "Sprite.h"

class EnemyBullet : public Sprite
{
private:
	float speed;

public:
	EnemyBullet(float px, float py);
	~EnemyBullet();

	void start();
	void update();

	void onTrigger(GameObject* other);
};
