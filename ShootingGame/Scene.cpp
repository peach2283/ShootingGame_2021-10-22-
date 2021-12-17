#include "framework.h"
#include "ShootingGame.h"

Scene::Scene(string name)
{
    this->name = name;
}

Scene::~Scene()
{}

void Scene::load()
{}

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

string Scene::getName()
{
    return name;
}