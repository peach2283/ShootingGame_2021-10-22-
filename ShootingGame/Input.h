#pragma once

#include <Windows.h>

//키코드 열거형
enum class KeyCode { upArrow = 0, downArrow = 1, leftArrow = 2, rightArrow = 3, space = 4, Z = 5 };

struct MousePosition
{
	int x;
	int y;
};

class Input
{
	//키보드 상태 열거형
	enum class State { keyUpRep = 0, keyDown = 1, keyDownRep = 2, keyUp = 3 };

private:
	static State state[9];
	static int   vKeyCode[9];

public:
	static void update();

	//마우스좌표 저장변수
	static MousePosition mousePosition;

	//키입력 상태..체크 함수//
	static bool getKey    (KeyCode keycode);
	static bool getKeyDown(KeyCode keycode);
	static bool getKeyUp  (KeyCode keycode);

	//마우스 버튼 상태..체크 함수//
	static bool getMoustButton	  (int button);
	static bool getMoustButtonDown(int button);
	static bool getMoustButtonUp  (int button);
};