#pragma once

#include "GameObject.h"
#include "Sprite.h"

///�÷��̾� HP Ŭ����//
class PlayerHp : public GameObject
{
private:
public:
	PlayerHp(float px, float py);
	~PlayerHp();

	void start();
};

//ü�¹� Ŭ����//
class HPBar : public Sprite
{
private:
	float fillAmount;
public:
	HPBar(float px, float py);
	~HPBar();

	void start();
	void draw();
};

//ü�¹� ��� Ŭ����//
class HPBG : public Sprite
{
private:
public:
	HPBG(float px, float py);
	~HPBG();

	void start();
};