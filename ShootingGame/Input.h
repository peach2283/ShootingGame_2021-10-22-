#pragma once

#include <Windows.h>

//키보드 상태 열거형
enum class State { keyUpRep = 0, keyDown = 1, keyDownRep = 2, keyUp = 3 };

class Input
{
private:
	static State state[9];
	static int   vKeyCode[9];

public:
	static void update();

	static bool getKey(int i);
	static bool getKeyDown(int i);
	static bool getKeyUp(int i);
};