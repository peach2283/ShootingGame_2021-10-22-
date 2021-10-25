#include "framework.h"
#include "ShootingGame.h"

float Time::startTime = 0;
float Time::endTime   = 0;
float Time::deltaTime = 0;

//Ÿ��(��ŸŸ��) �ʱ�ȭ
void Time::init()
{
	startTime = (float)GetTickCount64() / (float)1000;
	endTime   = 0;
	deltaTime = 0;
}

//Ÿ��(��ŸŸ��) ������Ʈ
void Time::update()
{
	//���ð� ����
	endTime = (float)GetTickCount64() / (float)1000;

	//��ŸŸ��
	deltaTime = endTime - startTime;

	//printf("��Ÿ Ÿ�� %f\n", deltaTime);

	//���۽ð� ����
	startTime = (float)GetTickCount64() / (float)1000;
}