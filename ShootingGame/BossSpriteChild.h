#pragma once

#include "Sprite.h"

class BossSpriteChild : public Sprite
{
private:
	float hp;
	float ex, ey; //����ȿ�� ���� ��ġ

public:
	BossSpriteChild(string tag, string name, bool active, float px, float py, float ex, float ey);
	~BossSpriteChild();

	void onTrigger(GameObject* other);
	void explode();
};