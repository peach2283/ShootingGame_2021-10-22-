#include "framework.h"
#include "ShootingGame.h"

GameBG::GameBG(float px, float py) : Sprite("���", "", true, px, py)
{}

GameBG::~GameBG()
{}

void GameBG::start()
{
	//�̹���(��������Ʈ)�ε�
	setImage("Asset/���ӹ��.bmp");
}

void GameBG::update()
{

}
