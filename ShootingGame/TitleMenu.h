#pragma once
#include "Button.h"

////타이틀 시작 버튼 클래스/////
class Start : public Button
{
private:
public:
	Start(float px, float py);
	~Start();

	void start();
	void onClick();
};


////타이틀 끝내기 버튼 클래스///
class Quit : public Button
{
private:
public:
	Quit(float px, float py);
	~Quit();

	void start();
	void onClick();
};