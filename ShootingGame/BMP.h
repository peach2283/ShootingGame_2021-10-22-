#pragma once

struct Image
{
	int width;
	int height;
	unsigned int* argb;
};

class BMP
{
private:
public:
	static void readBMP(const char* fileName, Image* image);
	static void drawBMP(float  px, float py , Image* image);
};
