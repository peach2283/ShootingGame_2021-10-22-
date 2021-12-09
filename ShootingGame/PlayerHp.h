#pragma once

#include "GameObject.h"
#include "Sprite.h"

///플레이어 HP 클래스//
class PlayerHp : public GameObject
{
private:
public:
	PlayerHp(float px, float py);
	~PlayerHp();

	void start();
};

//체력바 클래스//
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

//체력바 배경 클랙스//
class HPBG : public Sprite
{
private:
public:
	HPBG(float px, float py);
	~HPBG();

	void start();
};