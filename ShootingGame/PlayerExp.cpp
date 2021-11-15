#include "framework.h"
#include "ShootingGame.h"

PlayerExp::PlayerExp(float px, float py) : Animation("", "", true, px, py)
{}

PlayerExp::~PlayerExp()
{}

void PlayerExp::start()
{
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			addImage("Asset/Æø¹ßÈ¿°ú.bmp", 0+col*129, 4286 + row*129, 128, 128, 0);
		}
	}
}

void PlayerExp::onAnimationEnd()
{
	destroy(this);
}