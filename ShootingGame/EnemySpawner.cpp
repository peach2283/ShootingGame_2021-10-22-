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
		//ȭ�鿡..�����ִ� ���ⰹ��
		int spawnCount   = GameManager::getEnemySpawnCount();   //������ ���ⰹ��
		int destroyCount = GameManager::getEnemyDestroyCount(); //���ŵ� ���ⰹ��

		int leftCount = spawnCount - destroyCount;  //���� ȭ�鿡..���� ���ⰹ��
		
		if (leftCount < 2)
		{
			//���⽺���ϱ�//
			float px = getPx();
			float py = getPy();

			int    spawnIdx		  = Random::range(0, 3); //0,1,2
			float  spawnPos[3][2] = { {px - 95 - 120, py - 137}, {px - 95      , py - 137}, {px - 95 + 120, py - 137} };

			instantiate(new Enemy(spawnPos[spawnIdx][0],  spawnPos[spawnIdx][1] , spawnCount), 1);

			spawnTimer = 0;

			//���⽺������..������Ű��(������ ���ؼ�..���ӸŴ����� ī��Ʈ����)
			GameManager::addEnemySpawnCount();
		}
	}
}

void EnemySpawner::onDrawGizmos()
{
	//EnemySpawner�� ��ġ�� ȭ�鿡..�����//
	float px = getPx();
	float py = getPy();

	drawLine(px - 30, py     , px + 30, py      , 255, 0, 0);
	drawLine(px     , py - 30, px      , py + 30, 255, 0, 0);
}