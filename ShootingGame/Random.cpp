#include "framework.h"
#include "ShootingGame.h"

//���� ���� �ʱ�ȭ
void Random::init()
{
	srand(time(nullptr));
}

//���� �߻� �Լ�
int Random::range(int min, int max)
{
	int r = rand() % (max - min) + min;
	return r;
}