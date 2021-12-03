#include "framework.h"
#include "ShootingGame.h"

CannonBall::CannonBall(float px, float py, float angle) : Sprite("","",true, px, py)
{
	this->speed = 100;
	this->angle = angle;
}

CannonBall::~CannonBall()
{}

void CannonBall::start()
{
	setImage("Asset/총알2.bmp");
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