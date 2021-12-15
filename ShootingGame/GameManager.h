#pragma once

#define MAX_ENEMY 20

class GameManager
{
private:
	static int enemySpawnCount;   //���� ���� ī��Ʈ
	static int enemyDestroyCount; //���� ���� ī��Ʈ

	static int playerCount; //���ӿ���.. ���� �÷��̾� ī��Ʈ

	//���� �Ѿ�(������)������ �����迭
	static bool dropBulletItem[MAX_ENEMY];

	//��ź ������ ���� �迭
	static bool dropBombItem[MAX_ENEMY];

	//�����Ͻ����� ���� ����
	static bool isPause;

	//�÷��̾� ü��
	static float hp;   

	//���� ��ź ����
	static int bombCount; 

	//���� ����
	static int score;

public:

	static void addEnemySpawnCount();
	static void addEnemyDestroyCount();

	static int getEnemySpawnCount();
	static int getEnemyDestroyCount();

	static void reSpawnPlayer(); 

	static bool doDropBulletItem(int num);
	static bool doDropBombItem(int num);

	static bool getIsPause();
	static void setIsPause(bool pause);

	static void  damage(float amount);
	static float getHP();

	static int getPlayerCount();

	static int  getBombCount();
	static void subBombCount();
	static void addBombCount();

	static void addScore(int point);
	static int  getScore();
};
