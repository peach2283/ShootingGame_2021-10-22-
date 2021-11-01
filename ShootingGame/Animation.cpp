#include "framework.h"
#include "ShootingGame.h"

Animation::Animation(string tag, string name, bool active, float px, float py)
		 :GameObject(tag, name, active, px, py)
{
	this->imageIndex = 0;
	this->clipIndex  = 2;

	this->imageTimer = 0;
	this->imageDelay = 0.05;
}

Animation::~Animation()
{}

void Animation::start()
{
	Image img;

	//피해가 없는 적기 애니메이션 클립 - 0 번 클립//
	for (int i = 0; i < 2; i++)
	{
		BMP::readBMP("Asset/적기.bmp", 1 + 200 * i, 281, 190, 137, &img);  //i번 이미지
		image[0].push_back(img);
	}

	//중간 피해를 받은 적기 애니메이션 클립 - 1 번 클립 //
	for (int i = 0; i < 4; i++)
	{
		BMP::readBMP("Asset/적기.bmp", 1 + 200 * i, 141, 190, 137, &img);  //i번 이미지
		image[1].push_back(img);
	}

	//심각한 피해를 받은 적기 애니메이션 클립 - 2 번 클립//
	for (int i = 0; i < 4; i++)
	{
		BMP::readBMP("Asset/적기.bmp", 1 + 200 * i, 1, 190, 137, &img);  //i번 이미지
		image[2].push_back(img);
	}
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
			imageIndex = 0;
		}

		imageTimer = 0;
	}
}