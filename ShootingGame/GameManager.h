#pragma once

class GameManager
{
private:
	static int enemySpawnCount;   //���� ���� ī��Ʈ
	static int enemyDestroyCount; //���� ���� ī��Ʈ

public:

	static void addEnemySpawnCount();
	static void addEnemyDestroyCount();

	static int getEnemySpawnCount();
	static int getEnemyDestroyCount();
};
