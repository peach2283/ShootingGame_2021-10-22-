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
	if (isPause == true)  //��������
	{		
		Time::timeScale = 1;  //��������
		isPause = false;      //�������� ����
	}
	else {  //��������

		Time::timeScale = 0;  //��������
		isPause = true;      //�������� ����
	}	
}