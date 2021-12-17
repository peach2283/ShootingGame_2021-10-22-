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
    ObjectManager::clear(); //�Ŵ��� ��Ͽ� �߰��� ��ü ��� �����ϱ�
}

string Scene::getName()
{
    return name;
}