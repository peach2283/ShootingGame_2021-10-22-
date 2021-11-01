#pragma once

#include "GameObject.h"
#include <vector>
#include "BMP.h"

using namespace std;

class Animation : public GameObject
{
private:
	
	vector<Image> image[10];
	
	int  imageIndex; //현재 재생중인 애니메이션의 이미지 선택
	int  clipIndex;  //현재 재생할...애니메이션을 선택

	float imageTimer;
	float imageDelay;

public:
	Animation(string tag, string name, bool active, float px, float py);
	~Animation();

	void start();
	void draw();
};