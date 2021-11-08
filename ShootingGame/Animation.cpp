#include "framework.h"
#include "ShootingGame.h"

Animation::Animation(string tag, string name, bool active, float px, float py)
		 :GameObject(tag, name, active, px, py)
{
	this->imageIndex = 0;
	this->clipIndex  = 0;

	this->imageTimer = 0;
	this->imageDelay = 0.05;

	this->loop = true;
}

Animation::~Animation()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < image[i].size(); j++)
		{
			delete[] image[i][j].argb;
		}

		image[i].clear();
	}
}

void Animation::start()
{
}

void Animation::play(int clip)
{
	if (clipIndex != clip)
	{
		imageIndex = 0;
		clipIndex = clip;
	}
}

void Animation::setLoop(bool loop)
{
	this->loop = loop;
}

void Animation::setImageDelay(float delay)
{
	this->imageDelay = delay;
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

	//이미지 시간 측정하기//
	imageTimer = imageTimer + Time::deltaTime;

	if (imageTimer >= imageDelay)
	{
		imageIndex++;

		if ( imageIndex  >= image[clipIndex].size() )
		{
			if (loop == true)
			{
				imageIndex = 0; //처음이미지 부터..반복(looping)
			}
			else {
				imageIndex = image[clipIndex].size() - 1; //마지막..이미지로..유지
			}

			//애니메이션...마지막 이미지 출력 이벤트 만들기//
			onAnimationEnd();
		}

		imageTimer = 0;
	}
}

void Animation::onAnimationEnd()
{}