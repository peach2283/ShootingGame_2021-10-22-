#include "framework.h"
#include "ShootingGame.h"

CannonBall::CannonBall(float px, float py, float angle) : Sprite("보스포탄","",true, px, py)
{
	this->speed = 100;
	this->angle = angle;
}

CannonBall::~CannonBall()
{}

void CannonBall::start()
{
	setImage("Asset/총알2.bmp");
	addBoxCollider2D(new BoxCollider2D(0, 0, 17, 17));

	destroy(this, 10);
}

void CannonBall::update()
{
	//x축 방향 벡터
	float nx=1, ny=0;

	//방향 벡터 회전시키기
	float theta = angle*M_PI/180;

	float x = nx * cos(theta) * speed * Time::deltaTime;
	float y = nx * sin(theta) * speed * Time::deltaTime;

	//방향벡터로..이동
	translate(x, y);
}

void CannonBall::onTrigger(GameObject* other)
{
	string tag = other->getTag();

	if (tag == "플레이어" || tag == "폭탄폭발" || tag == "방패")
	{
		//적기 총알 폭발//
		float px = getPx();
		float py = getPy();

		instantiate(new BulletExp(px - 5, py - 5));

		//적기 총알 제거//
		destroy(this);
	}
}