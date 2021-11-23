#pragma once

#include "Sprite.h"

class BulletItem : public Sprite
{
private:
public:
	BulletItem(float px, float py);
	~BulletItem();

	void start();
	void onTrigger(GameObject* other);
};
