#include "framework.h"
#include "ShootingGame.h"

TitleScene::TitleScene()
{}

TitleScene::~TitleScene()
{}

void TitleScene::load()
{
	//Ÿ��Ʋ ���//
	ObjectManager::instantiate(new TitleBG(0, 0));

	//Ÿ��Ʋ UI//
}