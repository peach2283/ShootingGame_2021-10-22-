#include "framework.h"
#include "ShootingGame.h"

TitleBG::TitleBG(float px, float py) : Sprite("","",true, px, py)
{}

TitleBG::~TitleBG()
{}

void TitleBG::start()
{
	setImage("Asset/Ÿ��Ʋ���.bmp");
}