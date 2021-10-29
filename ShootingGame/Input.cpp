#include "framework.h"
#include "ShootingGame.h"

State Input::state[9]    = { State::keyUpRep,State::keyUpRep,State::keyUpRep,State::keyUpRep,State::keyUpRep,State::keyUpRep,State::keyUpRep,State::keyUpRep,State::keyUpRep };
int   Input::vKeyCode[9] = { VK_UP          , VK_DOWN       , VK_LEFT       , VK_RIGHT      , VK_SPACE      , 'Z'           , VK_LBUTTON          , VK_RBUTTON      , VK_MBUTTON };

void Input::update()
{
    /////////////////////////////////////////////////
    /////// 키입력 만들기 ////////////////////////////
    for (int i = 0; i < 9; i++)
    {
        int key = GetAsyncKeyState(vKeyCode[i]);

        if (state[i] == State::keyUpRep)
        {
            if (key != 0)  //키가 눌렸음
            {
                state[i] = State::keyDown; //키가 한번눌림 상태로..전이
            }

        }
        else if (state[i] == State::keyDown)
        {
            if (key != 0) //키가 눌렸음
            {
                state[i] = State::keyDownRep; //키를 누르고 있는 상태로..전이
            }
            else {
                state[i] = State::keyUp;     //키를 한번 놓음 상태로..전이
            }

        }
        else if (state[i] == State::keyDownRep)
        {
            if (key == 0) //키가 눌리지 않음
            {
                state[i] = State::keyUp;      //키를 한번 놓음 상태로..전이
            }
        }
        else if (state[i] == State::keyUp)
        {
            if (key != 0) //키가 눌림
            {
                state[i] = State::keyDown;  //키를 한번 눌림 상태로..전이
            }
            else {
                state[i] = State::keyUpRep;  //키를 계속 놓고 있음 상태로..전이
            }
        }
    }

}

bool Input::getKey(KeyCode keycode)
{
    if ( state[(int) keycode] == State::keyDownRep || state[(int)keycode]==State::keyDown )
    {
        return true;
    }
    else {
        return false;
    }
}

bool Input::getKeyDown(KeyCode keycode)
{
    if (state[(int) keycode] == State::keyDown)
    {
        return true;
    }
    else {
        return false;
    }
}

bool Input::getKeyUp(KeyCode keycode)
{
    if (state[(int)keycode] == State::keyUp)
    {
        return true;
    }
    else {
        return false;
    }
}

bool Input::getMoustButton(int button)
{
    //button 이 0 이면..왼쪽   마우스 버튼(VK_LBUTTON)이고..상태..배열 인덱스 6
    //button 이 1 이면..오른쪽 마우스 버튼(VK_RBUTTON)이고..상태..배열 인덱스 7
    //button 이 2 이면..가운데 마우스 버튼(VK_MBUTTON)이고..상태..배열 인덱스 8

    if (state[button + 6] == State::keyDownRep || state[button + 6] == State::keyDown)
    {
        return true;
    }
    else {
        return false;
    }
}

bool Input::getMoustButtonDown(int button)
{
    if (state[button + 6] == State::keyDown)
    {
        return true;
    }
    else {
        return false;
    }
}

bool Input::getMoustButtonUp(int button)
{
    if (state[button + 6] == State::keyUp)
    {
        return true;
    }
    else {
        return false;
    }
}
