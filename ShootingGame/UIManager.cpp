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

    bombIcon[0] = instantiate(new BombIcon(10    , 720), 9);
    bombIcon[1] = instantiate(new BombIcon(10+30 , 720), 9);
    bombIcon[2] = instantiate(new BombIcon(10+60 , 720), 9);
    bombIcon[3] = instantiate(new BombIcon(10+90 , 720), 9);
    bombIcon[4] = instantiate(new BombIcon(10+120, 720), 9);

    //��Ʈ �׽�Ʈ �ϱ�
    instantiate(new Text(100, 100 , L"ü�� ����", 255, 255, 255, 64), 9);
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

    //��ź������ UI�� �����ϱ�//
    int bombCount = GameManager::getBombCount();

    for (int i = 0; i < 5; i++)
    {
        if (i < bombCount)
        {
            bombIcon[i]->setActive(true);
        }
        else {
            bombIcon[i]->setActive(false);
        }
    }
}