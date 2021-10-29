#include "framework.h"
#include "ShootingGame.h"

State Input::state[9]    = { State::keyUpRep,State::keyUpRep,State::keyUpRep,State::keyUpRep,State::keyUpRep,State::keyUpRep,State::keyUpRep,State::keyUpRep,State::keyUpRep };
int   Input::vKeyCode[9] = { VK_UP          , VK_DOWN       , VK_LEFT       , VK_RIGHT      , VK_SPACE      , 'Z'           , VK_LBUTTON          , VK_RBUTTON      , VK_MBUTTON };

void Input::update()
{
    /////////////////////////////////////////////////
    /////// Ű�Է� ����� ////////////////////////////
    for (int i = 0; i < 9; i++)
    {
        int key = GetAsyncKeyState(vKeyCode[i]);

        if (state[i] == State::keyUpRep)
        {
            if (key != 0)  //Ű�� ������
            {
                state[i] = State::keyDown; //Ű�� �ѹ����� ���·�..����
            }

        }
        else if (state[i] == State::keyDown)
        {
            if (key != 0) //Ű�� ������
            {
                state[i] = State::keyDownRep; //Ű�� ������ �ִ� ���·�..����
            }
            else {
                state[i] = State::keyUp;     //Ű�� �ѹ� ���� ���·�..����
            }

        }
        else if (state[i] == State::keyDownRep)
        {
            if (key == 0) //Ű�� ������ ����
            {
                state[i] = State::keyUp;      //Ű�� �ѹ� ���� ���·�..����
            }
        }
        else if (state[i] == State::keyUp)
        {
            if (key != 0) //Ű�� ����
            {
                state[i] = State::keyDown;  //Ű�� �ѹ� ���� ���·�..����
            }
            else {
                state[i] = State::keyUpRep;  //Ű�� ��� ���� ���� ���·�..����
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
    //button �� 0 �̸�..����   ���콺 ��ư(VK_LBUTTON)�̰�..����..�迭 �ε��� 6
    //button �� 1 �̸�..������ ���콺 ��ư(VK_RBUTTON)�̰�..����..�迭 �ε��� 7
    //button �� 2 �̸�..��� ���콺 ��ư(VK_MBUTTON)�̰�..����..�迭 �ε��� 8

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
