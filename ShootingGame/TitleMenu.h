#pragma once
#include "Button.h"

////Ÿ��Ʋ ���� ��ư Ŭ����/////
class Start : public Button
{
private:
public:
	Start(float px, float py);
	~Start();

	void start();
	void onClick();
};


////Ÿ��Ʋ ������ ��ư Ŭ����///
class Quit : public Button
{
private:
public:
	Quit(float px, float py);
	~Quit();

	void start();
	void onClick();
};