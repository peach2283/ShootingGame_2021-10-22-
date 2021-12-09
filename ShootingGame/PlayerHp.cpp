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

	//�̹���(���ö���Ʈ)�׸���
	float px = getPx();
	float py = getPy();

	BMP::drawBMP(px, py, &image, fillAmount);
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