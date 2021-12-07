#include "framework.h"
#include "ShootingGame.h"

int GameManager::enemySpawnCount   = 0;
int GameManager::enemyDestroyCount = 0;

int GameManager::playerCount = 3; 

bool GameManager::dropBulletItem[MAX_ENEMY] = { false, false, false, false, false,
												false, false, true , false, false,
												false, false, false, true , false,
												false, false, true , false, true };

bool GameManager::dropBombItem[MAX_ENEMY]   = { false, false, false, false, false,
												false, false, false, false, true,
												false, false, false, false, true,
												false, true , false, true , false };

bool GameManager::isPause = false;

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

void GameManager::reSpawnPlayer()
{
	playerCount--;  //�÷��̾� ī��Ʈ ����

	if (playerCount > 0)
	{
		//�÷��̾� �������ϱ�
		ObjectManager::instantiate(new Player(WIDTH / 2 - 34, HEIGHT + 50), 1); //�÷��̾� �߰� - 1�� ���̾�
	}
	else {
		//���ӿ���
		ObjectManager::instantiate(new GameOver((WIDTH - 420) / 2, 200) , 9); //UI�� �������� ���̾� �Ҵ�
	}
}

bool GameManager::doDropBulletItem(int num)
{
	return dropBulletItem[num];
}

bool GameManager::doDropBombItem(int num)
{
	return dropBombItem[num];
}