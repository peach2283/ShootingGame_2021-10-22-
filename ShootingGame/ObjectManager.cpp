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
					//�浹 �ڽ� ��ǥ ���ϱ�//
					float x, y, width, height;
					float x0I, y0I, x1I, y1I;    //objI(colI)�� �ڽ� �浹ü ��ǥ
					float x0J, y0J, x1J, y1J;    //objJ(colJ)�� �ڽ� �浹ü ��ǥ

					colI->getBoudingBox(x, y, width, height);
					x0I = x;
					y0I = y;
					x1I = x0I + width;
					y1I = y0I + height;

					colJ->getBoudingBox(x, y, width, height);
					x0J = x;
					y0J = y;
					x1J = x0J + width;
					y1J = y0J + height;

					if (y0I < y1J && y1I > y0J && x1I > x0J && x0I < x1J)
					{
						cout << "(" << objI->getTag() << " , " << objJ->getTag() << ") �浹��";
					}
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
		gameObject[i]->draw();          //�̹��� �׸���
		gameObject[i]->onDrawGizmos();  //����� �׸���
	}
}

void ObjectManager::clear()
{
	for (int i = 0; i <gameObject.size(); i++)
	{
		delete gameObject[i];
	}
}