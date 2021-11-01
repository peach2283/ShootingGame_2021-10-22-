#include "framework.h"
#include "ShootingGame.h"

Animation::Animation(string tag, string name, bool active, float px, float py)
		 :GameObject(tag, name, active, px, py)
{
	this->imageIndex = 0;
	this->clipIndex  = 0;

	this->imageTimer = 0;
	this->imageDelay = 0.05;
}

Animation::~Animation()
{}

void Animation::start()
{
	
}

void Animation::addImage(const char* fileName, int x, int y, int width, int height, int clip)
{
	Image img;

	BMP::readBMP(fileName, x, y, width, height, &img);
	image[clip].push_back(img);
}

void Animation::draw()
{
	float px = getPx();
	float py = getPy();

	BMP::drawBMP(px, py, &image[clipIndex][imageIndex]);

	//�̹��� �ð� �����ϱ�//
	imageTimer = imageTimer + Time::deltaTime;

	if (imageTimer >= imageDelay)
	{
		imageIndex++;

		if ( imageIndex  >= image[clipIndex].size() )
		{
			imageIndex = 0;
		}

		imageTimer = 0;
	}
}