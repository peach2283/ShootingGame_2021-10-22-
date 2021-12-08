#include "framework.h"
#include "ShootingGame.h"

BTNPause::BTNPause(float px, float py) : Button(px, py)
{
}

BTNPause::~BTNPause()
{}

void BTNPause::start()
{
	setImage("Asset/UI/btnPause.bmp");
}

void BTNPause::onClick()
{
	if (GameManager::getIsPause() == true)  //게임정지
	{		
		Time::timeScale = 1;				//게임진행
		GameManager::setIsPause(false);      //게임진행 상태
	}
	else {  //게임진행

		Time::timeScale = 0;				//게임정지
		GameManager::setIsPause(true);      //게임정지 상태
	}	
}