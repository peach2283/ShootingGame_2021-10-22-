#include "framework.h"
#include "ShootingGame.h"

vector<GameObject* > ObjectManager::gameObject;

void ObjectManager::instantiate(GameObject* o)
{
	gameObject.push_back(o);
	o->start();
}

void ObjectManager::update()
{
	for (int i = 0; i < gameObject.size(); i++)
	{
		gameObject[i]->update();
	}
}

void ObjectManager::draw()
{
	for (int i = 0; i < gameObject.size(); i++)
	{
		gameObject[i]->draw();
	}
}

void ObjectManager::clear()
{
	for (int i = 0; i <gameObject.size(); i++)
	{
		delete gameObject[i];
	}
}