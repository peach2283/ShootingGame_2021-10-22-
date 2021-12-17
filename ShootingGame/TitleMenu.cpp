#include "framework.h"
#include "ShootingGame.h"

////Ÿ��Ʋ ���� ��ư Ŭ����/////
Start::Start(float px, float py) : Button(px,py)
{}

Start::~Start()
{}

void Start::start()
{
	setImage("Asset/UI/����.bmp");
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
	setImage("Asset/UI/������.bmp");
}

void Quit::onClick()
{
	Application::quit();
}