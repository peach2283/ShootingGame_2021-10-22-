#pragma once

#include <ft2build.h>  //옵션에 지정된 경로에서...헤더 포함하기
#include FT_FREETYPE_H //기타 필요한 헤더 포함
#include "GameObject.h"

class Text : public GameObject
{
private:
	FT_Library library;
	FT_Face face;

	unsigned char r, g, b; //폰트 색상
	wstring text;
	int size;

public:
	Text(string name, float px, float py, wstring text, unsigned char r, unsigned char g, unsigned char b, int size);
	~Text();

	void start();
	void draw();

	void setText(wstring text);
};