#pragma once

#include "Button.h"

class BTNPause : public Button
{
private:
	bool isPause;  //true(����), false(����)

public:
	BTNPause(float px, float py);
	~BTNPause();

	void start();

	//Ŭ�� �̺�Ʈ �������̵�
	void onClick();
};
