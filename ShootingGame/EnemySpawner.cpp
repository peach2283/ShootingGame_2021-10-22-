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
		//화면에..남아있는 적기갯수
		int spawnCount   = GameManager::getEnemySpawnCount();   //스폰된 적기갯수
		int destroyCount = GameManager::getEnemyDestroyCount(); //제거된 적기갯수

		int leftCount = spawnCount - destroyCount;  //현재 화면에..남은 적기갯수
		
		if (leftCount < 5)
		{
			//적기스폰하기//
			float px = getPx();
			float py = getPy();

			int spawnPos = Random::range(0, 3); //0,1,2

			cout << "스폰 랜던 위치 " << spawnPos << endl;

			instantiate(new Enemy(px - 95, py - 137));

			spawnTimer = 0;

			//적기스폰갯수..증가시키기(공유를 위해서..게임매니저의 카운트변수)
			GameManager::addEnemySpawnCount();
		}
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