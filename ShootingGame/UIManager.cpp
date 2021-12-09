#include "framework.h"
#include "ShootingGame.h"

UIManager::UIManager() : GameObject("", "", true, 0,0)
{}

UIManager::~UIManager()
{}

void UIManager::start()
{
    //UI �߰��ϱ�
    instantiate(new BTNExit(420, 5), 9);
    instantiate(new BTNPause(370, 5), 9);

    popupMenu = instantiate(new PopupMenu((WIDTH - 245) / 2, 200), 9);

    instantiate(new PlayerHp(20, 10), 9);
}

void UIManager::update()
{
    ///���ӸŴ����� ���������� UI�� �����ϱ�//////
    if (GameManager::getIsPause() == true)
    {       
        popupMenu->setActive(true);
    }
    else {        
        popupMenu->setActive(false);
    }

    //���ӸŴ����� �÷��̾� ü���� UI�������ϱ�///
    cout << "�÷��̾� ü�� " << GameManager::getHP() << endl;
}