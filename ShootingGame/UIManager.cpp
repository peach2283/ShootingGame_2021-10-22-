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
    playerHP  = instantiate(new PlayerHp(20, 15), 9);

    playerIcon[0] = instantiate(new PlayerIcon(220   , 5), 9);
    playerIcon[1] = instantiate(new PlayerIcon(220+40, 5), 9);
    playerIcon[2] = instantiate(new PlayerIcon(220+80, 5), 9);
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
    HPBar * hpBar =(HPBar*) playerHP->find("ü�¹�");

    if (hpBar != nullptr)
    {
        float fillAmount = GameManager::getHP() / 100.0;
        hpBar->setFillAmount(fillAmount);
    }

    //�÷��̾� ī��Ʈ�� UI�� �����ϱ�//
    int playerCount = GameManager::getPlayerCount();

    for (int i = 0; i < 3; i++)
    {
        if (i < playerCount)
        {
            playerIcon[i]->setActive(true);
        }
        else {
            playerIcon[i]->setActive(false);
        }
    }
}