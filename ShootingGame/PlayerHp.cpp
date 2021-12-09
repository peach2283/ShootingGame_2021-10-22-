#include "framework.h"
#include "ShootingGame.h"

//////////플레이어 체력 ////////////////
PlayerHp::PlayerHp(float px, float py) : GameObject("", "", true, px, py)
{}

PlayerHp::~PlayerHp()
{}

void PlayerHp::start()
{
	addChildObject(new HPBG (0, 0), 9);
	addChildObject(new HPBar(2, 2), 9);
}

////////////체력바 ///////////////////
HPBar::HPBar(float px, float py) : Sprite("", "", true, px, py)
{}

HPBar::~HPBar()
{}

void HPBar::start()
{
	setImage("Asset/UI/HPBar.bmp");
}

/////////체력(바) 배경//////////////////
HPBG::HPBG(float px, float py) : Sprite("","",true, px, py)
{}

HPBG::~HPBG()
{}

void HPBG::start()
{
	setImage("Asset/UI/HPBG.bmp");
}