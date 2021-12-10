#pragma once

#include "GameObject.h"

class UIManager : public GameObject
{
private:

	//�˾��޴�..������ ����
	GameObject* popupMenu;

	//�÷��̾� ü�¹�..������ ����
	GameObject* playerHP;

	//�÷��̾� ���� ������..������ ���� �迭
	GameObject* playerIcon[3];

	//��ź ���� ������...������ ���� �迭
	GameObject* bombIcon[5];

public:
	UIManager();
	~UIManager();

	void start();
	void update();
};
