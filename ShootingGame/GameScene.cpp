#include "framework.h"
#include "ShootingGame.h"

GameScene::GameScene() : Scene("GameScene")
{}

GameScene::~GameScene()
{}

void GameScene::load()
{   
   //게임씬의 상태..초기화하기
   Time::timeScale = 1.0;
   GameManager::reset();

   //게임오브젝트..추가하기//
   ObjectManager::instantiate(new GameBG(0, 0));                           //게임배경 추가
   ObjectManager::instantiate(new Player(WIDTH / 2 - 34, HEIGHT + 50), 1); //플레이어 추가 - 1번 레이어

   //적기스포너
   ObjectManager::instantiate(new EnemySpawner(WIDTH / 2, 0));

   //UIManager 추가하기//
   ObjectManager::instantiate(new UIManager());  
}