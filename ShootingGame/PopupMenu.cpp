#include "framework.h"
#include "ShootingGame.h"

//////////////////�޴� �����̹���////////////////////
PopupMenu::PopupMenu(float px, float py) : Sprite("","",false, px, py)
{}

PopupMenu::~PopupMenu()
{}

void PopupMenu::start()
{
	setImage("Asset/UI/menu.bmp");

	////�޴� ������ ��ư �ڽ� ��ü �߰��ϱ�///
	addChildObject(new ItemResume (16,  20         ), 9);
	addChildObject(new ItemRestart(16,  20+37      ), 9);
	addChildObject(new ItemMain   (16,  20+37+37   ), 9);
	addChildObject(new ItemExit   (16,  20+37+37+37), 9);
}

////////////////Exit �޴� ������////////////////////
ItemExit::ItemExit(float px, float py) : Button(px, py)
{
	setActive(false);
}

ItemExit::~ItemExit()
{}

void ItemExit::start()
{
	setImage("Asset/UI/itemExit.bmp");
}

void ItemExit::onClick()
{
	Application::quit();
}

////////////////Main �޴� ������////////////////////
ItemMain::ItemMain(float px, float py) : Button(px, py)
{
	setActive(false);
}

ItemMain::~ItemMain()
{}

void ItemMain::start()
{
	setImage("Asset/UI/itemMain.bmp");
}

void ItemMain::onClick()
{
	SceneManager::loadScene("TitleScene");
}

////////////////Restart �޴� ������////////////////////
ItemRestart::ItemRestart(float px, float py) : Button(px, py)
{
	setActive(false);
}

ItemRestart::~ItemRestart()
{}

void ItemRestart::start()
{
	setImage("Asset/UI/itemRestart.bmp");
}

void ItemRestart::onClick()
{
	SceneManager::loadScene("GameScene");
}

////////////////Resume �޴� ������////////////////////
ItemResume::ItemResume(float px, float py) : Button(px, py)
{
	setActive(false);
}

ItemResume::~ItemResume()
{}

void ItemResume::start()
{
	setImage("Asset/UI/itemResume.bmp");
}

void ItemResume::onClick()
{
	//�Ͻ����� �簳�ϱ�
	GameManager::setIsPause(false);
	Time::timeScale = 1.0;
}