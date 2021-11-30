#include "framework.h"
#include "ShootingGame.h"

Propeller::Propeller(float px, float py) : Animation("보스자식","",true,px , py)
{}

Propeller::~Propeller()
{}

void Propeller::start()
{
	//피해없는 프로펠러 - 0 번 애니메이션//
	addImage("Asset/보스.bmp", 7 + 34 * 0, 439, 32, 12, 0);
	addImage("Asset/보스.bmp", 7 + 34 * 1, 439, 32, 12, 0);

	//연기나는 프로펠러 - 1 번 애니메이션//
	addImage("Asset/보스.bmp", 7 + 34 * 0, 455, 32, 52, 1);
	addImage("Asset/보스.bmp", 7 + 34 * 1, 455, 32, 52, 1);

	//애니메이션 속도 지정
	setImageDelay(0.1);
}