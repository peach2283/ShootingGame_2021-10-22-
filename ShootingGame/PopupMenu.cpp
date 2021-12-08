#include "framework.h"
#include "ShootingGame.h"

//////////////////�޴� �����̹���////////////////////
PopupMenu::PopupMenu(float px, float py) : Sprite("","",true, px, py)
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
{}

ItemExit::~ItemExit()
{}

void ItemExit::start()
{
	setImage("Asset/UI/itemExit.bmp");
}

void ItemExit::onClick()
{
	cout << "������ �޴� ������ " << endl;
}

////////////////Main �޴� ������////////////////////
ItemMain::ItemMain(float px, float py) : Button(px, py)
{}

ItemMain::~ItemMain()
{}

void ItemMain::start()
{
	setImage("Asset/UI/itemMain.bmp");
}

void ItemMain::onClick()
{
	cout << "Ÿ��Ʋ�ΰ��� �޴� ������ " << endl;
}

////////////////Restart �޴� ������////////////////////
ItemRestart::ItemRestart(float px, float py) : Button(px, py)
{}

ItemRestart::~ItemRestart()
{}

void ItemRestart::start()
{
	setImage("Asset/UI/itemRestart.bmp");
}

void ItemRestart::onClick()
{
	cout << "�ٽý��� �޴� ������ " << endl;
}

////////////////Resume �޴� ������////////////////////
ItemResume::ItemResume(float px, float py) : Button(px, py)
{}

ItemResume::~ItemResume()
{}

void ItemResume::start()
{
	setImage("Asset/UI/itemResume.bmp");
}

void ItemResume::onClick()
{
	cout << "��������..�ٽ��ϱ� �޴� ������ " << endl;
}