#include "framework.h"
#include "ShootingGame.h"

DeadBoss::DeadBoss(float px, float py) : Sprite("","",true, px, py)
{
	this->speed = 50;
}

DeadBoss::~DeadBoss()
{}

void DeadBoss::start()
{
	//보스 폭발 후 이미지로 변경		
	setImage("Asset/보스.bmp", 0, 613, 385, 182);

	//데드 보스...죽는 시간 지정하기
	destroy(this, 5);
}

void DeadBoss::update()
{
	translate(0, speed * Time::deltaTime);
}

void DeadBoss::onDestroy()
{
	cout << "---미션 완료 / 스테이지 클리어---" << endl;
}