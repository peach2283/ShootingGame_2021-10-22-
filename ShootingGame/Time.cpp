#include "framework.h"
#include "ShootingGame.h"

float Time::startTime = 0;
float Time::endTime   = 0;
float Time::deltaTime = 0;

//타임(델타타임) 초기화
void Time::init()
{
	startTime = (float)GetTickCount64() / (float)1000;
	endTime   = 0;
	deltaTime = 0;
}

//타임(델타타임) 업데이트
void Time::update()
{
	//끝시간 측정
	endTime = (float)GetTickCount64() / (float)1000;

	//델타타임
	deltaTime = endTime - startTime;

	//printf("델타 타임 %f\n", deltaTime);

	//시작시간 측정
	startTime = (float)GetTickCount64() / (float)1000;
}