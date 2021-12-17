#include "framework.h"
#include "ShootingGame.h"

TitleScene::TitleScene() : Scene("TitleScene")
{}

TitleScene::~TitleScene()
{}

void TitleScene::load()
{
	//타이틀 배경//
	ObjectManager::instantiate(new TitleBG(0, 0));

	//타이틀 UI//
	//ObjectManager::instantiate(new Text(50, 60, L"2D 슈팅게임", 0, 0, 0, 64), 9);

	ObjectManager::instantiate(new Start(250, 500), 9);
	ObjectManager::instantiate(new Quit (250, 560), 9);
}