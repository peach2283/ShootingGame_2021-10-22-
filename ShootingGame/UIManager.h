#pragma once

#include "GameObject.h"

class UIManager : public GameObject
{
private:

	//팝업메뉴..포인터 저장
	GameObject* popupMenu;

	//플레이어 체력바..포인터 저장
	GameObject* playerHP;

	//플레이어 갯수 아이콘..포인터 저장 배열
	GameObject* playerIcon[3];

public:
	UIManager();
	~UIManager();

	void start();
	void update();
};
