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

    instantiate(new Text("", 5, 35, L"체력", 255, 255, 255, 20), 9);
    playerHP  = instantiate(new PlayerHp(45, 15), 9);

    instantiate(new Text("", 5, 68, L"점수", 255, 255, 255, 20), 9);

    playerIcon[0] = instantiate(new PlayerIcon(230   , 5), 9);
    playerIcon[1] = instantiate(new PlayerIcon(230+40, 5), 9);
    playerIcon[2] = instantiate(new PlayerIcon(230+80, 5), 9);

    bombIcon[0] = instantiate(new BombIcon(10    , 720), 9);
    bombIcon[1] = instantiate(new BombIcon(10+30 , 720), 9);
    bombIcon[2] = instantiate(new BombIcon(10+60 , 720), 9);
    bombIcon[3] = instantiate(new BombIcon(10+90 , 720), 9);
    bombIcon[4] = instantiate(new BombIcon(10+120, 720), 9);

    //폰트 테스트 하기
    //instantiate(new Text(100, 100 , L"체력_점수,", 255, 255, 255, 64), 9);
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
    HPBar * hpBar =(HPBar*) playerHP->find("체력바");

    if (hpBar != nullptr)
    {
        float fillAmount = GameManager::getHP() / 100.0;
        hpBar->setFillAmount(fillAmount);
    }

    Text* hpValue =(Text*) playerHP->find("체력값");

    if (hpValue != nullptr)
    {
        //sprintf로 실수를 문자열로 변환하기
        WCHAR buffer[20];
        wsprintf(buffer, L"%d", (int) GameManager::getHP());

        hpValue->setText(buffer);
    }

    //플레이어 카운트를 UI에 적용하기//
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

    //폭탄갯수를 UI에 적용하기//
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

    //게임 점수를 UI에 적용하기//
    int score = GameManager::getScore();
    cout << "게임 점수 " << score << endl;
}