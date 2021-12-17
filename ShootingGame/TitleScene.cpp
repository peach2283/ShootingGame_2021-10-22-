#include "framework.h"
#include "ShootingGame.h"

TitleScene::TitleScene() : Scene("TitleScene")
{}

TitleScene::~TitleScene()
{}

void TitleScene::load()
{
	//Ÿ��Ʋ ���//
	ObjectManager::instantiate(new TitleBG(0, 0));

	//Ÿ��Ʋ UI//
	//ObjectManager::instantiate(new Text(50, 60, L"2D ���ð���", 0, 0, 0, 64), 9);

	ObjectManager::instantiate(new Start(250, 500), 9);
	ObjectManager::instantiate(new Quit (250, 560), 9);
}