#pragma once

class GameManager
{
private:
	static int enemySpawnCount;   //적기 스폰 카운트
	static int enemyDestroyCount; //적기 제거 카운트

public:

	static void addEnemySpawnCount();
	static void addEnemyDestroyCount();

	static int getEnemySpawnCount();
	static int getEnemyDestroyCount();
};
