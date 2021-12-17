#include "framework.h"
#include "ShootingGame.h"

GameScene::GameScene() : Scene("GameScene")
{}

GameScene::~GameScene()
{}

void GameScene::load()
{   
   //���Ӿ��� ����..�ʱ�ȭ�ϱ�
   Time::timeScale = 1.0;
   GameManager::reset();

   //���ӿ�����Ʈ..�߰��ϱ�//
   ObjectManager::instantiate(new GameBG(0, 0));                           //���ӹ�� �߰�
   ObjectManager::instantiate(new Player(WIDTH / 2 - 34, HEIGHT + 50), 1); //�÷��̾� �߰� - 1�� ���̾�

   //���⽺����
   ObjectManager::instantiate(new EnemySpawner(WIDTH / 2, 0));

   //UIManager �߰��ϱ�//
   ObjectManager::instantiate(new UIManager());  
}