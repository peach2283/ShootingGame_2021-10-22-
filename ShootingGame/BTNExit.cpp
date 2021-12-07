#include "framework.h"
#include "ShootingGame.h"

BTNExit::BTNExit(float px, float py) : Button(px, py)
{}

BTNExit::~BTNExit()
{}

void BTNExit::start()
{
	setImage("Asset/UI/btnExit.bmp");
}

void BTNExit::onClick()
{
	cout << "Exit버튼이 클리됨" << endl;
}