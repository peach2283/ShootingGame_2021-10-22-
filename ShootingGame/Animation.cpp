#include "framework.h"
#include "ShootingGame.h"

Animation::Animation(string tag, string name, bool active, float px, float py)
		 :GameObject(tag, name, active, px, py)
{}

Animation::~Animation()
{}

void Animation::start()
{
	BMP::readBMP("Asset/����.bmp", 201, 141, 190, 137, &image);
}

void Animation::draw()
{
	float px = getPx();
	float py = getPy();

	BMP::drawBMP(px, py, &image);
}