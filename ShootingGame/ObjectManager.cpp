#include "framework.h"
#include "ShootingGame.h"

vector<GameObject* > ObjectManager::gameObject;

void ObjectManager::instantiate(GameObject* o)
{
	gameObject.push_back(o);
	o->start();
}

void ObjectManager::destroy(GameObject* o)
{
	//삭제 객체를 .. 충돌이후에 삭제되어야 한다는..정보를 표시하고..충돌이후에..실제로 제거함
	o->setIsDead(true);
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
					//충돌 박스 좌표 구하기//
					float x, y, width, height;
					float x0I, y0I, x1I, y1I;    //objI(colI)의 박스 충돌체 좌표
					float x0J, y0J, x1J, y1J;    //objJ(colJ)의 박스 충돌체 좌표

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
						//objI 하고 objJ ... 게임오브젝트가 충돌함
						objI->onTrigger(objJ); //objI의 함수를 이용해서..objJ와 충돌(Trigger)이 발생했음을..알림
						objJ->onTrigger(objI); //objJ의 함수를 이용해서..objI와 충돌(Trigger)이 발생했음을..알림
					}
				}
			}
		}		
	}	
}

void ObjectManager::clearDeadObject()
{
	/////////////////////삭제로..표시된...객체를 제거함///////////
	for (int i = 0; i < gameObject.size(); i++)
	{
		if (gameObject[i]->getIsDead() == true)  //삭제로..표시된 객체
		{
			GameObject* o = gameObject[i];

			//stl vector 목록에서 제거
			gameObject.erase(gameObject.begin() + i);
			i--;

			//객체 delete 하기
			delete o;
		}
	}
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