#include "framework.h"
#include "ShootingGame.h"

//////////////////메뉴 바탕이미지////////////////////
PopupMenu::PopupMenu(float px, float py) : Sprite("","",false, px, py)
{}

PopupMenu::~PopupMenu()
{}

void PopupMenu::start()
{
	setImage("Asset/UI/menu.bmp");

	////메뉴 아이템 버튼 자식 객체 추가하기///
	addChildObject(new ItemResume (16,  20         ), 9);
	addChildObject(new ItemRestart(16,  20+37      ), 9);
	addChildObject(new ItemMain   (16,  20+37+37   ), 9);
	addChildObject(new ItemExit   (16,  20+37+37+37), 9);
}

////////////////Exit 메뉴 아이템////////////////////
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

////////////////Main 메뉴 아이템////////////////////
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

////////////////Restart 메뉴 아이템////////////////////
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

////////////////Resume 메뉴 아이템////////////////////
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
	//일시정지 재개하기
	GameManager::setIsPause(false);
	Time::timeScale = 1.0;
}