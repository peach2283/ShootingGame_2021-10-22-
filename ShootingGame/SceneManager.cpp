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
			activeScene->unload();      //������ ��ε�
			activeScene = sceneList[i]; //���ο������..��Ƽ��� ������ ����
			activeScene->load();        //���ο�� �ε�

			break;
		}
	}
}