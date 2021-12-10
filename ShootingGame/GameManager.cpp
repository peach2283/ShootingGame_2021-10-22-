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

bool GameManager::isPause  = false;
float GameManager::hp      = 100;
int GameManager::bombCount = 3;

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

void GameManager::reSpawnPlayer()
{
	playerCount--;  //플레이어 카운트 감소

	if (playerCount > 0)
	{
		//플레이어 리스폰하기
		ObjectManager::instantiate(new Player(WIDTH / 2 - 34, HEIGHT + 50), 1); //플레이어 추가 - 1번 레이어

		//플레이어 체력 복구
		hp = 100;
	}
	else {
		//게임오버
		ObjectManager::instantiate(new GameOver((WIDTH - 420) / 2, 200) , 9); //UI는 가장위의 레이어 할당
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

bool GameManager::getIsPause()
{
	return isPause;
}

void GameManager::setIsPause(bool pause)
{
	isPause = pause;
}

void GameManager::damage(float amount)
{
	hp = hp - amount;
}

float GameManager::getHP()
{
	return hp;
}

int GameManager::getPlayerCount()
{
	return playerCount;
}

int GameManager::getBombCount()
{
	return bombCount;
}

void GameManager::subBombCount()
{
	bombCount--;
}

void GameManager::addBombCount()
{
	if (bombCount < 5)
	{
		bombCount++;
	}
}