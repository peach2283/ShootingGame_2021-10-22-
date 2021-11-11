#include "framework.h"
#include "ShootingGame.h"

EnemyExp::EnemyExp(float px, float py) : Animation("","",true, px, py)
{}

EnemyExp::~EnemyExp()
{}

void EnemyExp::start()
{
	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			addImage("Asset/Æø¹ßÈ¿°ú.bmp", 0+x*129, 183 + 105*y, 128, 104, 0);
		}
	}

	addImage("Asset/Æø¹ßÈ¿°ú.bmp", 0 + 0 * 129, 183 + 105 * 3, 128, 104, 0);
	addImage("Asset/Æø¹ßÈ¿°ú.bmp", 0 + 1 * 129, 183 + 105 * 3, 128, 104, 0);
	addImage("Asset/Æø¹ßÈ¿°ú.bmp", 0 + 2 * 129, 183 + 105 * 3, 128, 104, 0);
}

void EnemyExp::onAnimationEnd()
{
	destroy(this);
}