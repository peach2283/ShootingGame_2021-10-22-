#pragma once

#include "Button.h"

class BTNPause : public Button
{
private:
	bool isPause;  //true(정지), false(진행)

public:
	BTNPause(float px, float py);
	~BTNPause();

	void start();

	//클릭 이벤트 오버라이딩
	void onClick();
};
