#define _CRT_SECURE_NO_WARNINGS

#include "framework.h"
#include "ShootingGame.h"

void BMP::readBMP(const char* fileName, Image* image)
{
	//��Ʈ�� ���� �ε��ϱ�//
	BITMAPFILEHEADER bf;
	BITMAPINFOHEADER bi;

	FILE* stream;

	stream = fopen(fileName, "rb");

	if (stream != nullptr)
	{
		//��Ʈ������ ��� �о����//
		fread(&bf, sizeof(BITMAPFILEHEADER), 1, stream);

		//��Ʈ������ ��� �о����//
		fread(&bi, sizeof(BITMAPINFOHEADER), 1, stream);

		//��Ʈ�� ���� ���..����ϱ�//
		//printf("----��Ʈ�� ���� ���----\n");
		//printf("bfType : 0X%X\n", bf.bfType);  //0x4D(M), 0x42(B) : ��Ʈ�� ���� Ȯ�� �ڵ�(�����ڵ�)
		//printf("bfSize : %d ����Ʈ\n", bf.bfSize);  //���� ũ��
		//printf("bfReserved1 : %d\n", bf.bfReserved1);
		//printf("bfReserved2 : %d\n", bf.bfReserved2);
		//printf("bfOffBits : %d\n", bf.bfOffBits);

		//��Ʈ�� ���� ���..����ϱ�//
		//printf("----��Ʈ�� ���� ��� ----\n");
		//printf("biWidth    : %d\n", bi.biWidth);
		//printf("biHeight   : %d\n", bi.biHeight);
		//printf("biBitCount : %d\n", bi.biBitCount);
		//printf("biSizeImage : %d ����Ʈ \n", bi.biSizeImage);

		//��Ʈ��..�ȼ�����Ÿ..�о����//
		int length = bi.biSizeImage / 4;
		unsigned int* argb = new unsigned int[length];

		fread(argb, sizeof(unsigned int), length, stream);

		//printf("��Ʈ�� ������ �ε��߽��ϴ�\n");

		//�ε���..��Ʈ�� ����/����Ÿ��...����ü �迭��..����//
		image->width  = bi.biWidth;  //�̹��� ����
		image->height = bi.biHeight; //�̹��� ����
		image->argb   = argb;        //�̹��� �ȼ�����Ÿ

		//���ϴݱ�
		fclose(stream);
	}
	else {
		printf("��Ʈ�� ������ ���� �����ϴ�\n");
	}
}

void BMP::readBMP(const char* fileName, int x, int y, int width, int height, Image* image)
{
	//��Ʈ�� ���� �ε��ϱ�//
	BITMAPFILEHEADER bf;
	BITMAPINFOHEADER bi;

	FILE* stream;

	stream = fopen(fileName, "rb");

	if (stream != nullptr)
	{
		//��Ʈ������ ��� �о����//
		fread(&bf, sizeof(BITMAPFILEHEADER), 1, stream);

		//��Ʈ������ ��� �о����//
		fread(&bi, sizeof(BITMAPINFOHEADER), 1, stream);
		
		//(x, y, width, height) �簢�� ������...��Ʈ��..�ȼ�����Ÿ..�о����//
		//[1] �о����..����Ÿ..��ġ����..�̵��ϱ�
		
		int offset = bi.biWidth * y * 4 + x * 4;
		fseek(stream, offset, SEEK_CUR);

		//[2] ����Ÿ..���� �޸�..�Ҵ��ϱ�
		int length         = width * height;
		unsigned int* argb = new unsigned int[length];

		//����Ÿ..�б���.. �̵���
		int hGap = (bi.biWidth - width)*4;

		//[3] ��Ʈ��..����Ÿ..�б�
		for (int i = 0; i < height; i++)
		{
			fread(argb + i*width, sizeof(unsigned int), width, stream);
			fseek(stream        , hGap, SEEK_CUR);
		}

		//�ε���..��Ʈ�� ����/����Ÿ��...����ü �迭��..����//
		image->width  = width;  //�̹��� ����
		image->height = height; //�̹��� ����
		image->argb   = argb;    //�̹��� �ȼ�����Ÿ

		//���ϴݱ�
		fclose(stream);
	}
	else {
		printf("��Ʈ�� ������ ���� �����ϴ�\n");
	}

}

void BMP::drawBMP(float px, float py, Image* image, float fillAmount)
{
	//�ε��� �̹��� ����ϱ�//
	for (int y = 0; y < image->height; y++)
	{
		for (int x = 0; x < image->width * fillAmount ; x++)
		{
			unsigned int pixel = image->argb[y * image->width + x];
			setPixel(px + x, py + y, pixel);
		}
	}
}
