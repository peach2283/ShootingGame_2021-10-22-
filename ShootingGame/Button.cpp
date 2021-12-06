#include "framework.h"
#include "ShootingGame.h"

Button::Button(float px, float py) : Sprite("","", true, px, py)
{}

Button::~Button()
{}

void Button::start()
{
	setImage("Asset/UI/item.bmp");
}

void Button::update()
{
	if (Input::getMoustButtonDown(0) == true)
	{
		float mx = Input::mousePosition.x;
		float my = Input::mousePosition.y;

		cout << "마우스 버튼이 눌림 " << endl;
		cout << "마우스 좌표 (" << mx << " " << my << ")" << endl;
	}
}