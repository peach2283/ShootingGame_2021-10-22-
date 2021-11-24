#pragma once

class GameManager
{
private:
	static int enemySpawnCount;   //적기 스폰 카운트
	static int enemyDestroyCount; //적기 제거 카운트

	static int playerCount; //게임에서.. 남은 플레이어 카운트

	//적기 총알(레이저)아이템 생성배열
	static bool dropBulletItem[20];

public:

	static void addEnemySpawnCount();
	static void addEnemyDestroyCount();

	static int getEnemySpawnCount();
	static int getEnemyDestroyCount();

	static void reSpawnPlayer(); 
};
