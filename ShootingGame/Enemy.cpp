#include "framework.h"
#include "ShootingGame.h"

Enemy::Enemy(float px, float py) : Animation("","",true, px, py)
{}

Enemy::~Enemy()
{}

void Enemy::start()
{
	//애니메이션 이미지들..로드하기//
	//피해가 없는 적기 애니메이션 클립 - 0 번 클립//
	for (int i = 0; i < 2; i++)
	{
		addImage("Asset/적기.bmp", 1 + 200 * i, 281, 190, 137, 0);  //i번 이미지
	}

	//중간 피해를 받은 적기 애니메이션 클립 - 1 번 클립 //
	for (int i = 0; i < 4; i++)
	{
		addImage("Asset/적기.bmp", 1 + 200 * i, 141, 190, 137, 1);  //i번 이미지	
	}

	//심각한 피해를 받은 적기 애니메이션 클립 - 2 번 클립//
	for (int i = 0; i < 4; i++)
	{
		addImage("Asset/적기.bmp", 1 + 200 * i, 1, 190, 137, 2);  //i번 이미지
	}

	//충돌체 추가하기
	addBoxCollider2D(new BoxCollider2D(0, 0, 190, 137));
}

void Enemy::update()
{}