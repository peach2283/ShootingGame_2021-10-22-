#pragma once

#include "GameObject.h"

class EnemySpawner : public GameObject
{
private:

	//스폰시간 조정 변수//
	float spawnTimer;
	float spawnDelay;

public:
	EnemySpawner(float px, float py);
	~EnemySpawner();

	void update();

	//onDrawGizmos 오버라이딩//
	void onDrawGizmos();
};
