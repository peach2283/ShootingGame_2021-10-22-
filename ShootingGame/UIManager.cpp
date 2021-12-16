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

    instantiate(new Text(5, 35, L"ü��", 255, 255, 255, 20), 9);
    playerHP  = instantiate(new PlayerHp(45, 15), 9);

    instantiate(new Text(5,  68, L"����", 255, 255, 255, 20), 9);
    gameScore=instantiate(new Text(50, 68, L"000", 255, 255, 255, 20),  9);

    playerIcon[0] = instantiate(new PlayerIcon(230   , 5), 9);
    playerIcon[1] = instantiate(new PlayerIcon(230+40, 5), 9);
    playerIcon[2] = instantiate(new PlayerIcon(230+80, 5), 9);

    bombIcon[0] = instantiate(new BombIcon(10    , 720), 9);
    bombIcon[1] = instantiate(new BombIcon(10+30 , 720), 9);
    bombIcon[2] = instantiate(new BombIcon(10+60 , 720), 9);
    bombIcon[3] = instantiate(new BombIcon(10+90 , 720), 9);
    bombIcon[4] = instantiate(new BombIcon(10+120, 720), 9);

    instantiate(new Text(300, 785, L"���ð��� Ver 1.0", 0, 0, 0, 20), 9);
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

    Text* hpValue =(Text*) playerHP->find("ü�°�");

    if (hpValue != nullptr)
    {
        //sprintf�� �Ǽ��� ���ڿ��� ��ȯ�ϱ�
        WCHAR buffer[20];
        wsprintf(buffer, L"%d", (int) GameManager::getHP());

        hpValue->setText(buffer);
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

    //���� ������ UI�� �����ϱ�//
    int score = GameManager::getScore();
    
    WCHAR temp[20];
    wsprintf(temp, L"%03d", score);

    ((Text*)gameScore)->setText(temp);
}