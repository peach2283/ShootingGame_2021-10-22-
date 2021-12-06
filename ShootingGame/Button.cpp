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

		cout << "���콺 ��ư�� ���� " << endl;
		cout << "���콺 ��ǥ (" << mx << " " << my << ")" << endl;
	}
}