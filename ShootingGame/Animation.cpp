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

	//�̹��� �ð� �����ϱ�//
	imageTimer = imageTimer + Time::deltaTime;

	if (imageTimer >= imageDelay)
	{
		imageIndex++;

		if ( imageIndex  >= image[clipIndex].size() )
		{
			if (loop == true)
			{
				imageIndex = 0; //ó���̹��� ����..�ݺ�(looping)
			}
			else {
				imageIndex = image[clipIndex].size() - 1; //������..�̹�����..����
			}

			//�ִϸ��̼�...������ �̹��� ��� �̺�Ʈ �����//
			onAnimationEnd();
		}

		imageTimer = 0;
	}
}

void Animation::onAnimationEnd()
{}