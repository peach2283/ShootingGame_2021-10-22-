#include "framework.h"
#include "ShootingGame.h"

Shield::Shield(float px, float py) : Animation("방패", "방패", true , px, py)
{
	this->activeTimer = 5;
}

Shield::~Shield()
{}

void Shield::start()
{
	//방패 애니메이션 이미지 추가
	addImage("Asset/보호방패1.bmp", 0);
	addImage("Asset/보호방패2.bmp", 0);
	addImage("Asset/보호방패3.bmp", 0);

	//충돌체 추가
	addBoxCollider2D(new BoxCollider2D(0, 0, 90, 90));
}

void Shield::update()
{
	/**
	activeTimer = activeTimer - Time::deltaTime;

	if (activeTimer <= 0)
	{
		//방패 비활성화 하기
		setActive(false);
	}
	**/
}