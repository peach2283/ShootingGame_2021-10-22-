#pragma once

#include <ft2build.h>  //�ɼǿ� ������ ��ο���...��� �����ϱ�
#include FT_FREETYPE_H //��Ÿ �ʿ��� ��� ����
#include "GameObject.h"

class Text : public GameObject
{
private:
	FT_Library library;
	FT_Face face;

	unsigned char r, g, b; //��Ʈ ����
	wstring text;
	int size;

public:
	Text(float px, float py, wstring text, unsigned char r, unsigned char g, unsigned char b, int size);
	Text(string name, float px, float py, wstring text, unsigned char r, unsigned char g, unsigned char b, int size);

	~Text();

	void start();
	void draw();

	void setText(wstring text);
};