#include "framework.h"
#include "ShootingGame.h"

Button::Button(float px, float py) : Sprite("","", true, px, py)
{
	this->state = State::normal;
}

Button::~Button()
{}

void Button::start()
{
	setImage("Asset/UI/item.bmp");
}

void Button::update()
{
	switch (state)
	{
		case State::normal:
		{
			if (Input::getMoustButtonDown(0) == true && isInImageRect() == true)  //����
			{
				state = State::pressed; //�������� ��ȯ
				translate(0, 1);        //���� ȿ��
			}
		}
		break;

		case State::pressed:
		{
			if (Input::getMoustButtonUp(0) == true && isInImageRect() == true) //����
			{
				state = State::released; //���� ������ȯ
				translate(0, -1);        //���� ȿ��

			}
			else if (isInImageRect() != true)
			{
				state = State::normal;  //�ʱ���·� ��ȯ
				translate(0, -1);        //���� ȿ��
			}
		}
		break;
		

		case State::released:
		{		
			state = State::click;
		}
		break;


		case State::click:
		{
		   //��ư ���۽���//
			state = State::normal;

			cout << "UI ��ư�� Ŭ���� - ��ư ���۽���" << endl;

		}
		break;

	}	
}

bool Button::isInImageRect()
{
	//���콺 ��ǥ
	short mx = Input::mousePosition.x;
	short my = Input::mousePosition.y;

	//��ư �̹��� ��ǥ
	float x0 = getPx();
	float y0 = getPy();

	float x1 = x0 + getWidth();
	float y1 = y0 + getHeight();

	if (x0 <= mx && mx <= x1 && y0 <= my && my <= y1)
	{
		//cout << "���콺 ��ư�� ���� " << endl;
		//cout << "���콺 ��ǥ (" << mx << " " << my << ")" << endl;

		return true;
	}
	else {
		return false;
	}
}