#pragma once

class GameManager
{
private:
	static int enemySpawnCount;   //���� ���� ī��Ʈ
	static int enemyDestroyCount; //���� ���� ī��Ʈ

	static int playerCount; //���ӿ���.. ���� �÷��̾� ī��Ʈ

	//���� �Ѿ�(������)������ �����迭
	static bool dropBulletItem[20];

public:

	static void addEnemySpawnCount();
	static void addEnemyDestroyCount();

	static int getEnemySpawnCount();
	static int getEnemyDestroyCount();

	static void reSpawnPlayer(); 
};
