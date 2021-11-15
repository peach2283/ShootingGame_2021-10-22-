#include "framework.h"
#include "ShootingGame.h"

EnemySpawner::EnemySpawner(float px, float py) : GameObject("","", true, px, py)
{}

EnemySpawner::~EnemySpawner()
{}


void EnemySpawner::onDrawGizmos()
{
	//EnemySpawner�� ��ġ�� ȭ�鿡..�����//
	float px = getPx();
	float py = getPy();

	drawLine(px - 30, py     , px + 30, py      , 255, 0, 0);
	drawLine(px     , py - 30, px      , py + 30, 255, 0, 0);
}