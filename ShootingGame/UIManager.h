#pragma once

#include "GameObject.h"

class UIManager : public GameObject
{
private:

	//�˾��޴�..������ ����
	GameObject* popupMenu;

public:
	UIManager();
	~UIManager();

	void start();
	void update();
};
