#pragma once
#include "Scene.h"

class SceneManager
{
private:

	static Scene * sceneList[2];
	static Scene * activeScene;

public:

	static void init();
	static void run();
	static void exit();

	static void loadScene(string name);
};
