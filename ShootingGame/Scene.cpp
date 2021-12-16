#include "framework.h"
#include "ShootingGame.h"

Scene::Scene()
{}

Scene::~Scene()
{}

void Scene::load()
{
    /****************************
    //게임오브젝트..추가하기//    
    ObjectManager::instantiate(new GameBG(0, 0));                           //게임배경 추가
    ObjectManager::instantiate(new Player(WIDTH / 2 - 34, HEIGHT + 50), 1); //플레이어 추가 - 1번 레이어

    //적기스포너
    ObjectManager::instantiate(new EnemySpawner(WIDTH / 2, 0));

    //UIManager 추가하기//
    ObjectManager::instantiate(new UIManager());
    ******************************/
}

void Scene::run()
{
    ObjectManager::update();
    ObjectManager::checkLifeTime();
    ObjectManager::checkCollision();
    ObjectManager::clearDeadObject();
    ObjectManager::draw();
}

void Scene::unload()
{
    ObjectManager::clear(); //매니저 목록에 추가된 객체 모두 삭제하기
}