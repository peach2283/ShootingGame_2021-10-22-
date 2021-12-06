#include "framework.h"
#include "ShootingGame.h"

Sprite::Sprite(string tag, string name, bool active, float px, float py)
	   :GameObject(tag, name, active, px, py)
{
	image.width  = 0;
	image.height = 0;
	image.argb	 = nullptr;
}

Sprite::~Sprite()
{
	if (image.argb != nullptr)
	{
		delete[] image.argb;
	}
}

void Sprite::setImage(const char* fileName)
{
	BMP::readBMP(fileName, &image);
}

void Sprite::setImage(const char* fileName, int x, int y, int width, int height)
{
	BMP::readBMP(fileName, x, y, width, height, &image);
}

void Sprite::draw()
{
	//�̹���(���ö���Ʈ)�׸���
	float px = getPx();
	float py = getPy();

	BMP::drawBMP(px, py, &image);
}

int Sprite::getWidth()
{
	return image.width;
}

int Sprite::getHeight()
{
	return image.height;
}