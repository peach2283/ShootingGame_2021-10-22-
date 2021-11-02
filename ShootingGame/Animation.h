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

	bool loop;

public:
	Animation(string tag, string name, bool active, float px, float py);
	~Animation();

	void start();
	void draw();

	//�ִϸ��̼� �̹��� �ε��Լ�//
	void addImage(const char* fileName, int x, int y, int width, int height, int clip);

	//������� �ִϸ��̼�..�����ϱ�//
	void play(int clip);

	//looping ����
	void setLoop(bool loop);
};