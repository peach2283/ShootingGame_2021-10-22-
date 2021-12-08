#pragma once

#include "Button.h"

class BTNPause : public Button
{
private:
public:

	BTNPause(float px, float py);
	~BTNPause();

	void start();

	//클릭 이벤트 오버라이딩
	void onClick();
};
