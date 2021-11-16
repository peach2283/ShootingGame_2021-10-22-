#include "framework.h"
#include "ShootingGame.h"

int GameManager::enemySpawnCount   = 0;
int GameManager::enemyDestroyCount = 0;

void GameManager::addEnemySpawnCount()
{
	enemySpawnCount++;  //���⽺��ī��Ʈ ����
}

void GameManager::addEnemyDestroyCount()
{
	enemyDestroyCount++; //�������� ī��Ʈ ����
}

int GameManager::getEnemySpawnCount()
{
	return enemySpawnCount;
}

int GameManager::getEnemyDestroyCount()
{
	return enemyDestroyCount;
}