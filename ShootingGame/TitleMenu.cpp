#include "framework.h"
#include "ShootingGame.h"

////타이틀 시작 버튼 클래스/////
Start::Start(float px, float py) : Button(px,py)
{}

Start::~Start()
{}

void Start::start()
{
	setImage("Asset/UI/시작.bmp");
}

void Start::onClick()
{
	SceneManager::loadScene("GameScene");
}

Quit::Quit(float px, float py) : Button(px, py)
{}

Quit::~Quit()
{}

void Quit::start()
{
	setImage("Asset/UI/끝내기.bmp");
}

void Quit::onClick()
{
	Application::quit();
}