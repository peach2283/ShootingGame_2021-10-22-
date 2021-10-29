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
	static void readBMP(const char* fileName, int x, int y, int width, int height,  Image* image);


	static void drawBMP(float  px, float py , Image* image);
};
