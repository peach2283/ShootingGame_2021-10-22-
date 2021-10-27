#include "framework.h"
#include "ShootingGame.h"

State Input::state[9]    = { State::keyUpRep,State::keyUpRep,State::keyUpRep,State::keyUpRep,State::keyUpRep,State::keyUpRep,State::keyUpRep,State::keyUpRep,State::keyUpRep };
int   Input::vKeyCode[9] = { VK_UP          , VK_DOWN , VK_LEFT       , VK_RIGHT      , VK_SPACE      , 'Z'           , VK_LBUTTON          , VK_RBUTTON      , VK_MBUTTON };


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