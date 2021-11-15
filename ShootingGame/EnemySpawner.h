#pragma once

#include "GameObject.h"

class EnemySpawner : public GameObject
{
private:

	//�����ð� ���� ����//
	float spawnTimer;
	float spawnDelay;

public:
	EnemySpawner(float px, float py);
	~EnemySpawner();

	void update();

	//onDrawGizmos �������̵�//
	void onDrawGizmos();
};
