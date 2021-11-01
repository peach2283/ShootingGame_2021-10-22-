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

	//���ذ� ���� ���� �ִϸ��̼� Ŭ�� - 0 �� Ŭ��//
	for (int i = 0; i < 2; i++)
	{
		BMP::readBMP("Asset/����.bmp", 1 + 200 * i, 281, 190, 137, &img);  //i�� �̹���
		image[0].push_back(img);
	}

	//�߰� ���ظ� ���� ���� �ִϸ��̼� Ŭ�� - 1 �� Ŭ�� //
	for (int i = 0; i < 4; i++)
	{
		BMP::readBMP("Asset/����.bmp", 1 + 200 * i, 141, 190, 137, &img);  //i�� �̹���
		image[1].push_back(img);
	}

	//�ɰ��� ���ظ� ���� ���� �ִϸ��̼� Ŭ�� - 2 �� Ŭ��//
	for (int i = 0; i < 4; i++)
	{
		BMP::readBMP("Asset/����.bmp", 1 + 200 * i, 1, 190, 137, &img);  //i�� �̹���
		image[2].push_back(img);
	}
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