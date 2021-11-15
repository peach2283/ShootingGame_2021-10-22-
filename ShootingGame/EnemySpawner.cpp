#include "framework.h"
#include "ShootingGame.h"

EnemySpawner::EnemySpawner(float px, float py) : GameObject("","", true, px, py)
{
	this->spawnTimer = 0;
	this->spawnDelay = 1;
}

EnemySpawner::~EnemySpawner()
{}

void EnemySpawner::update()
{
	spawnTimer = spawnTimer + Time::deltaTime;

	if (spawnTimer >= spawnDelay)
	{
		//적기스폰하기//
		float px = getPx();
		float py = getPy();

		instantiate(new Enemy(px - 95, py - 137));

		spawnTimer = 0;
	}
}

void EnemySpawner::onDrawGizmos()
{
	//EnemySpawner의 위치를 화면에..출력함//
	float px = getPx();
	float py = getPy();

	drawLine(px - 30, py     , px + 30, py      , 255, 0, 0);
	drawLine(px     , py - 30, px      , py + 30, 255, 0, 0);
}