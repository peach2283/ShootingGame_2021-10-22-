#pragma once

#include "GameObject.h"
#include "BMP.h"

class Sprite : public GameObject
{
private:
	Image image;

public:
	Sprite(string tag, string name, bool active, float px, float py);
	~Sprite();

	void setImage(const char* fileName);
	void draw();
};