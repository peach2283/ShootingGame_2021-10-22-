#pragma once

#include "GameObject.h"
#include <vector>
#include "BMP.h"

using namespace std;

class Animation : public GameObject
{
private:
	
	vector<Image> image[10];
	
	int  imageIndex; //���� ������� �ִϸ��̼��� �̹��� ����
	int  clipIndex;  //���� �����...�ִϸ��̼��� ����

	float imageTimer;
	float imageDelay;

public:
	Animation(string tag, string name, bool active, float px, float py);
	~Animation();

	//�ִϸ��̼� �̹��� �ε��Լ�//
	void addImage(const char* fileName, int x, int y, int width, int height, int clip);

	void start();
	void draw();
};