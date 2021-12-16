#include "framework.h"
#include "ShootingGame.h"

Scene::Scene()
{}

Scene::~Scene()
{}

void Scene::load()
{
    /****************************
    //���ӿ�����Ʈ..�߰��ϱ�//    
    ObjectManager::instantiate(new GameBG(0, 0));                           //���ӹ�� �߰�
    ObjectManager::instantiate(new Player(WIDTH / 2 - 34, HEIGHT + 50), 1); //�÷��̾� �߰� - 1�� ���̾�

    //���⽺����
    ObjectManager::instantiate(new EnemySpawner(WIDTH / 2, 0));

    //UIManager �߰��ϱ�//
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
    ObjectManager::clear(); //�Ŵ��� ��Ͽ� �߰��� ��ü ��� �����ϱ�
}