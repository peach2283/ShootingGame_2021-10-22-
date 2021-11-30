#pragma once

#include "BossSpriteChild.h"

class Wing : public BossSpriteChild
{
private:
	
	int   num;
	float imgRect[8][4] = { {298, 425, 30, 18},
							{329, 426, 32, 16},
							{364, 426, 32, 16},
							{399, 426, 32, 16},

							{404, 406, 28, 15},
							{369, 406, 32, 16},
							{334, 406, 32, 16},
							{299, 406, 32, 16 } };

public:
	Wing(float px, float py, int num);
	~Wing();

	void start();
};
