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
	if (GameManager::getIsPause() == true)  //��������
	{		
		Time::timeScale = 1;				//��������
		GameManager::setIsPause(false);      //�������� ����
	}
	else {  //��������

		Time::timeScale = 0;				//��������
		GameManager::setIsPause(true);      //�������� ����
	}	
}