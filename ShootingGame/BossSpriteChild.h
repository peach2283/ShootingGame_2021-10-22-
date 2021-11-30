#pragma once

#include "Sprite.h"

class BossSpriteChild : public Sprite
{
private:
	float hp;
	float ex, ey; //폭발효과 적용 위치

public:
	BossSpriteChild(string tag, string name, bool active, float px, float py, float ex, float ey);
	~BossSpriteChild();

	void onTrigger(GameObject* other);
	void explode();
};