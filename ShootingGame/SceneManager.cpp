#include "framework.h"
#include "ShootingGame.h"

Scene* SceneManager::sceneList[2] = { 
									  new TitleScene(), 
									  new GameScene() 
									 };

Scene * SceneManager::activeScene  = nullptr;

void SceneManager::init()
{
	activeScene = new TitleScene();
	activeScene->load();
}

void SceneManager::run()
{
	activeScene->run();
}

void SceneManager::exit()
{
	activeScene->unload();
}

void SceneManager::loadScene(string name)
{
	for (int i = 0; i < 2; i++)
	{
		if (name == sceneList[i]->getName())
		{
			activeScene->unload();      //기존씬 언로드
			activeScene = sceneList[i]; //새로운씬으로..액티브씬 포인터 변경
			activeScene->load();        //새로운씬 로드

			break;
		}
	}
}