#pragma once

#include "Button.h"

class BTNExit : public Button
{
private:
public:
	BTNExit(float px, float py);
	~BTNExit();

	void start();

	//클릭 이벤트 오버리이딩
	void onClick();
};
