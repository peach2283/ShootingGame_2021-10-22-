#pragma once

#include "GameObject.h"
#include "BMP.h"

class Animation : public GameObject
{
private:
	Image image;

public:
	Animation(string tag, string name, bool active, float px, float py);
	~Animation();

	void start();
	void draw();
};