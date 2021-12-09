#pragma once

#include "GameObject.h"

class UIManager : public GameObject
{
private:

	//팝업메뉴..포인터 저장
	GameObject* popupMenu;

public:
	UIManager();
	~UIManager();

	void start();
	void update();
};
