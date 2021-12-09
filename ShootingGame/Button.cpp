#include "framework.h"
#include "ShootingGame.h"

Button::Button(float px, float py) : Sprite("","", true, px, py)
{
	this->state = State::normal;
}

Button::~Button()
{}

void Button::update()
{
	if (getActive() == true)
	{
		switch (state)
		{
		case State::normal:
		{
			if (Input::getMoustButtonDown(0) == true && isInImageRect() == true)  //눌림
			{
				state = State::pressed; //눌림상태 전환
				translate(0, 1);        //눌림 효과
			}
		}
		break;

		case State::pressed:
		{
			if (Input::getMoustButtonUp(0) == true && isInImageRect() == true) //놓음
			{
				state = State::released; //놓인 상태전환
				translate(0, -1);        //놓임 효과

			}
			else if (isInImageRect() != true)
			{
				state = State::normal;  //초기상태로 전환
				translate(0, -1);        //놓임 효과
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
			//버튼 동작실행//
			state = State::normal;

			//부모의 가상함수 실행
			onClick();
		}
		break;

		}
	}
}

bool Button::isInImageRect()
{
	//마우스 좌표
	short mx = Input::mousePosition.x;
	short my = Input::mousePosition.y;

	//버튼 이미지 좌표
	float x0 = getPx();
	float y0 = getPy();

	float x1 = x0 + getWidth();
	float y1 = y0 + getHeight();

	if (x0 <= mx && mx <= x1 && y0 <= my && my <= y1)
	{
		//cout << "마우스 버튼이 놓임 " << endl;
		//cout << "마우스 좌표 (" << mx << " " << my << ")" << endl;

		return true;
	}
	else {
		return false;
	}
}

void Button::onClick()
{
	cout << "UI 버튼이 클릭됨 - 버튼 동작실행" << endl;
}