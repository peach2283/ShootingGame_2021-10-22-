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

	addChildObject(new Text("체력값",80, 16, L"100", 255, 255, 255, 12), 9);
}

////////////체력바 ///////////////////
HPBar::HPBar(float px, float py) : Sprite("", "체력바", true, px, py)
{
	this->fillAmount = 1.0;
}

HPBar::~HPBar()
{}

void HPBar::start()
{
	setImage("Asset/UI/HPBar.bmp");
}

void HPBar::draw()
{
	Image image = getImage();

	//이미지(스플라이트)그리기
	float px = getPx();
	float py = getPy();

	BMP::drawBMP(px, py, &image, fillAmount);
}

void HPBar::setFillAmount(float fillAmount)
{
	this->fillAmount = fillAmount;
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