#include "framework.h"
#include "ShootingGame.h"

UIManager::UIManager() : GameObject("", "", true, 0,0)
{}

UIManager::~UIManager()
{}

void UIManager::start()
{
    //UI 추가하기
    instantiate(new BTNExit(420, 5), 9);
    instantiate(new BTNPause(370, 5), 9);

    popupMenu = instantiate(new PopupMenu((WIDTH - 245) / 2, 200), 9);

    instantiate(new PlayerHp(20, 10), 9);
}

void UIManager::update()
{
    ///게임매니저의 일저정지를 UI에 적용하기//////
    if (GameManager::getIsPause() == true)
    {       
        popupMenu->setActive(true);
    }
    else {        
        popupMenu->setActive(false);
    }

    //게임매니저의 플레이어 체력을 UI에적용하기///
    cout << "플레이어 체력 " << GameManager::getHP() << endl;
}