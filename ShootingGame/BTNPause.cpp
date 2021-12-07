#include "framework.h"
#include "ShootingGame.h"

BTNPause::BTNPause(float px, float py) : Button(px, py)
{
	this->isPause = false;
}

BTNPause::~BTNPause()
{}

void BTNPause::start()
{
	setImage("Asset/UI/btnPause.bmp");
}

void BTNPause::onClick()
{
	if (isPause == true)  //게임정지
	{		
		Time::timeScale = 1;  //게임진행
		isPause = false;      //게임진행 상태
	}
	else {  //게임진행

		Time::timeScale = 0;  //게임정지
		isPause = true;      //게임정지 상태
	}	
}