#pragma once

#include "Sprite.h"
#include "Button.h"

//////////////////�޴� �����̹���////////////////////
class PopupMenu : public Sprite
{
private:
public:
	PopupMenu(float px, float py);
	~PopupMenu();

	void start();
};

////////////////Exit �޴� ������////////////////////
class ItemExit : public Button
{
private:
public:
	ItemExit(float px, float py);
	~ItemExit();

	void start();
	void onClick();

};

////////////////Main(Title)�� ���� �޴� ������////////////////////
class ItemMain : public Button
{
private:
public:
	ItemMain(float px, float py);
	~ItemMain();

	void start();
	void onClick();

};

///////////////////////Restart �޴� ������//////////////////////
class ItemRestart : public Button
{
private:
public:
	ItemRestart(float px, float py);
	~ItemRestart();

	void start();
	void onClick();

};

////////////////Resume(���������ϰ�..�����簳) �޴� ������////////////////////
class ItemResume : public Button
{
private:
public:
	ItemResume(float px, float py);
	~ItemResume();

	void start();
	void onClick();
};