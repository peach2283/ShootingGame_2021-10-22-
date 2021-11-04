#include "framework.h"
#include "ShootingGame.h"

GameBG::GameBG(float px, float py) : Sprite("배경", "", true, px, py)
{}

GameBG::~GameBG()
{}

void GameBG::start()
{
	//이미지(스프라이트)로드
	setImage("Asset/게임배경.bmp");
}

void GameBG::update()
{

}
