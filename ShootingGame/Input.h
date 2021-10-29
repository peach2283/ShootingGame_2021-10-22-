#pragma once

#include <Windows.h>

//Ű�ڵ� ������
enum class KeyCode {upArrow=0, downArrow=1, leftArrow=2, rightArrow=3, space=4, Z=5};

//Ű���� ���� ������
enum class State { keyUpRep = 0, keyDown = 1, keyDownRep = 2, keyUp = 3 };

class Input
{
private:
	static State state[9];
	static int   vKeyCode[9];

public:
	static void update();

	//Ű�Է� ����..üũ �Լ�//
	static bool getKey    (KeyCode keycode);
	static bool getKeyDown(KeyCode keycode);
	static bool getKeyUp  (KeyCode keycode);

	//���콺 ��ư ����..üũ �Լ�//
	static bool getMoustButton	  (int button);
	static bool getMoustButtonDown(int button);
	static bool getMoustButtonUp  (int button);
};