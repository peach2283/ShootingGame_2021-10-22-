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

	//폭탄 갯수 아이콘...포인터 저장 배열
	GameObject* bombIcon[5];

	//점수출력 텍스트 .. 포인터 저장
	GameObject* gameScore;

public:
	UIManager();
	~UIManager();

	void start();
	void update();
};
