#pragma once

#include "Sprite.h"
#include "Button.h"

//////////////////메뉴 바탕이미지////////////////////
class PopupMenu : public Sprite
{
private:
public:
	PopupMenu(float px, float py);
	~PopupMenu();

	void start();
};

////////////////Exit 메뉴 아이템////////////////////
class ItemExit : public Button
{
private:
public:
	ItemExit(float px, float py);
	~ItemExit();

	void start();
	void onClick();

};

////////////////Main(Title)로 가기 메뉴 아이템////////////////////
class ItemMain : public Button
{
private:
public:
	ItemMain(float px, float py);
	~ItemMain();

	void start();
	void onClick();

};

///////////////////////Restart 메뉴 아이템//////////////////////
class ItemRestart : public Button
{
private:
public:
	ItemRestart(float px, float py);
	~ItemRestart();

	void start();
	void onClick();

};

////////////////Resume(정지해제하고..게임재개) 메뉴 아이템////////////////////
class ItemResume : public Button
{
private:
public:
	ItemResume(float px, float py);
	~ItemResume();

	void start();
	void onClick();
};