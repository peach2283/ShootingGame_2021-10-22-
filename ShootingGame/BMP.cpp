#define _CRT_SECURE_NO_WARNINGS

#include "framework.h"
#include "ShootingGame.h"

void BMP::readBMP(const char* fileName, Image* image)
{
	//비트맵 파일 로드하기//
	BITMAPFILEHEADER bf;
	BITMAPINFOHEADER bi;

	FILE* stream;

	stream = fopen(fileName, "rb");

	if (stream != nullptr)
	{
		//비트맵파일 헤더 읽어오기//
		fread(&bf, sizeof(BITMAPFILEHEADER), 1, stream);

		//비트맵인포 헤더 읽어오기//
		fread(&bi, sizeof(BITMAPINFOHEADER), 1, stream);

		//비트맵 파일 헤더..출력하기//
		//printf("----비트맵 파일 헤더----\n");
		//printf("bfType : 0X%X\n", bf.bfType);  //0x4D(M), 0x42(B) : 비트맵 파일 확인 코드(매직코드)
		//printf("bfSize : %d 바이트\n", bf.bfSize);  //파일 크기
		//printf("bfReserved1 : %d\n", bf.bfReserved1);
		//printf("bfReserved2 : %d\n", bf.bfReserved2);
		//printf("bfOffBits : %d\n", bf.bfOffBits);

		//비트맵 인포 헤더..출력하기//
		//printf("----비트맵 인포 헤더 ----\n");
		//printf("biWidth    : %d\n", bi.biWidth);
		//printf("biHeight   : %d\n", bi.biHeight);
		//printf("biBitCount : %d\n", bi.biBitCount);
		//printf("biSizeImage : %d 바이트 \n", bi.biSizeImage);

		//비트멥..픽셀데이타..읽어오기//
		int length = bi.biSizeImage / 4;
		unsigned int* argb = new unsigned int[length];

		fread(argb, sizeof(unsigned int), length, stream);

		//printf("비트맵 파일을 로드했습니다\n");

		//로드한..비트맵 정보/데이타를...구조체 배열에..저장//
		image->width  = bi.biWidth;  //이미지 가로
		image->height = bi.biHeight; //이미지 세로
		image->argb   = argb;        //이미지 픽셀데이타

		//파일닫기
		fclose(stream);
	}
	else {
		printf("비트맵 파일을 열수 없습니다\n");
	}
}

void BMP::readBMP(const char* fileName, int x, int y, int width, int height, Image* image)
{
	//비트맵 파일 로드하기//
	BITMAPFILEHEADER bf;
	BITMAPINFOHEADER bi;

	FILE* stream;

	stream = fopen(fileName, "rb");

	if (stream != nullptr)
	{
		//비트맵파일 헤더 읽어오기//
		fread(&bf, sizeof(BITMAPFILEHEADER), 1, stream);

		//비트맵인포 헤더 읽어오기//
		fread(&bi, sizeof(BITMAPINFOHEADER), 1, stream);
		
		//(x, y, width, height) 사각형 영역의...비트맵..픽셀데이타..읽어오기//
		//[1] 읽어들일..데이타..위치가까..이동하기
		
		int offset = bi.biWidth * y * 4 + x * 4;
		fseek(stream, offset, SEEK_CUR);

		//[2] 데이타..저장 메모리..할당하기
		int length         = width * height;
		unsigned int* argb = new unsigned int[length];

		//데이타..읽기후.. 이동값
		int hGap = (bi.biWidth - width)*4;

		//[3] 비트맵..데이타..읽기
		for (int i = 0; i < height; i++)
		{
			fread(argb + i*width, sizeof(unsigned int), width, stream);
			fseek(stream        , hGap, SEEK_CUR);
		}

		//로드한..비트맵 정보/데이타를...구조체 배열에..저장//
		image->width  = width;  //이미지 가로
		image->height = height; //이미지 세로
		image->argb   = argb;    //이미지 픽셀데이타

		//파일닫기
		fclose(stream);
	}
	else {
		printf("비트맵 파일을 열수 없습니다\n");
	}

}

void BMP::drawBMP(float px, float py, Image* image)
{
	//로드한 이미지 출력하기//
	for (int y = 0; y < image->height; y++)
	{
		for (int x = 0; x < image->width; x++)
		{
			unsigned int pixel = image->argb[y * image->width + x];
			setPixel(px + x, py + y, pixel);
		}
	}
}
