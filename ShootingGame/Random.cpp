#include "framework.h"
#include "ShootingGame.h"

//·£´ý ¾¾µå ÃÊ±âÈ­
void Random::init()
{
	srand(time(nullptr));
}

//·£´ý ¹ß»ý ÇÔ¼ö
int Random::range(int min, int max)
{
	int r = rand() % (max - min) + min;
	return r;
}