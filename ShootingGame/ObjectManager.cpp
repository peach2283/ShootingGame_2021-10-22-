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

void ObjectManager::checkCollision()
{
	cout << "----------------------------------" << endl;

	for (int i = 0; i < gameObject.size(); i++)
	{
		for (int j = 0; j < gameObject.size(); j++)
		{
			if (i < j)
			{
				GameObject* objI = gameObject[i];
				GameObject* objJ = gameObject[j];

				BoxCollider2D * colI = objI->getCollider();
				BoxCollider2D * colJ = objJ->getCollider();

				if (colI != nullptr && colJ != nullptr)
				{
					cout << "(" << objI->getTag() << " , " << objJ->getTag() << ") ";
				}
			}
		}

		cout << endl;
	}

	cout << endl;
}

void ObjectManager::draw()
{
	for (int i = 0; i < gameObject.size(); i++)
	{
		gameObject[i]->draw();          //이미지 그리기
		gameObject[i]->onDrawGizmos();  //기즈모 그리기
	}
}

void ObjectManager::clear()
{
	for (int i = 0; i <gameObject.size(); i++)
	{
		delete gameObject[i];
	}
}