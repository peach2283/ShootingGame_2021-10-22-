#include "framework.h"
#include "ShootingGame.h"

TitleScene::TitleScene()
{}

TitleScene::~TitleScene()
{}

void TitleScene::load()
{
	//타이틀 배경//
	ObjectManager::instantiate(new TitleBG(0, 0));

	//타이틀 UI//
}