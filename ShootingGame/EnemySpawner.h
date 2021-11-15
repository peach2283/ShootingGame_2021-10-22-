#pragma once

#include "GameObject.h"

class EnemySpawner : public GameObject
{
private:
public:
	EnemySpawner(float px, float py);
	~EnemySpawner();

	//onDrawGizmos 오버라이딩//
	void onDrawGizmos();
};
