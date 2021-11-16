#include "framework.h"
#include "ShootingGame.h"

int GameManager::enemySpawnCount   = 0;
int GameManager::enemyDestroyCount = 0;

void GameManager::addEnemySpawnCount()
{
	enemySpawnCount++;  //적기스폰카운트 증가
}

void GameManager::addEnemyDestroyCount()
{
	enemyDestroyCount++; //적기제거 카운트 증가
}

int GameManager::getEnemySpawnCount()
{
	return enemySpawnCount;
}

int GameManager::getEnemyDestroyCount()
{
	return enemyDestroyCount;
}