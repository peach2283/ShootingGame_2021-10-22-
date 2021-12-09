#include "framework.h"
#include "ShootingGame.h"

//////////�÷��̾� ü�� ////////////////
PlayerHp::PlayerHp(float px, float py) : GameObject("", "", true, px, py)
{}

PlayerHp::~PlayerHp()
{}

void PlayerHp::start()
{
	addChildObject(new HPBG (0, 0), 9);
	addChildObject(new HPBar(2, 2), 9);
}

////////////ü�¹� ///////////////////
HPBar::HPBar(float px, float py) : Sprite("", "", true, px, py)
{}

HPBar::~HPBar()
{}

void HPBar::start()
{
	setImage("Asset/UI/HPBar.bmp");
}

/////////ü��(��) ���//////////////////
HPBG::HPBG(float px, float py) : Sprite("","",true, px, py)
{}

HPBG::~HPBG()
{}

void HPBG::start()
{
	setImage("Asset/UI/HPBG.bmp");
}