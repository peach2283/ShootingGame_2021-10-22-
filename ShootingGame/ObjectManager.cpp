#include "framework.h"
#include "ShootingGame.h"

vector<GameObject* > ObjectManager::gameObject[10];

void ObjectManager::instantiate(GameObject* o, int layer)
{
	gameObject[layer].push_back(o);
	o->start();
}

void ObjectManager::destroy(GameObject* o)
{
	//삭제 객체를 .. 충돌이후에 삭제되어야 한다는..정보를 표시하고..충돌이후에..실제로 제거함
	o->setIsDead(true);
}

void ObjectManager::destroy(GameObject* o, float lifeTime)
{
	//바로삭제하기 않고...lifetime이 지나면..객체를 삭제함
	o->setLifeTime(lifeTime);
}

void ObjectManager::update()
{
	for (int j = 0; j < 10; j++)
	{
		for (int i = 0; i < gameObject[j].size(); i++)
		{
			gameObject[j][i]->update();
		}
	}
}

void ObjectManager::checkLifeTime()
{
	for (int j = 0; j < 10; j++)
	{
		for (int i = 0; i < gameObject[j].size(); i++)
		{
			gameObject[j][i]->subLifeTime();
		}
	}
}

void ObjectManager::checkObjectCollision(GameObject* objI, GameObject* objJ)
{
	//GameObject* objI = gameObject[layerI][i];  //layerI에서 i 번째...게임오브젝트
	//GameObject* objJ = gameObject[layerJ][j];  //layerJ에서 j 번째...게임오브젝트

	vector<BoxCollider2D*> colI = objI->getCollider();
	vector<BoxCollider2D*> colJ = objJ->getCollider();

	for (int ii = 0; ii < colI.size(); ii++)
	{
		for (int jj = 0; jj < colJ.size(); jj++)
		{
			//colI[ii]  충돌체와 colJ[jj] 충돌체와...충돌검사를 실시함
			//충돌 박스 좌표 구하기//
			float x, y, width, height;
			float x0I, y0I, x1I, y1I;    //objI(colI)의 박스 충돌체 좌표
			float x0J, y0J, x1J, y1J;    //objJ(colJ)의 박스 충돌체 좌표

			colI[ii]->getBoudingBox(x, y, width, height);
			x0I = x;
			y0I = y;
			x1I = x0I + width;
			y1I = y0I + height;


			colJ[jj]->getBoudingBox(x, y, width, height);
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

void ObjectManager::checkCollision()
{
	//충돌검사 레이어쌍 만들기//
	for (int layerI = 0; layerI < 10; layerI++)
	{
		for (int layerJ = 0; layerJ < 10; layerJ++)
		{
			if (layerI <= layerJ)
			{
			
				////////////////동일 레이어의..게임오브젝트들의..충돌검사///////////
				if (layerI == layerJ)
				{

					for (int i = 0; i < gameObject[layerI].size(); i++)
					{
						for (int j = 0; j < gameObject[layerJ].size(); j++)
						{

							if (i < j)
							{							

								checkObjectCollision( gameObject[layerI][i], gameObject[layerJ][j] );

							}											
						
						}
					}
				
				}
				else //////////다른 레이어의..게임오븢게트들의...충돌검사//////////
				{

					for (int i = 0; i < gameObject[layerI].size(); i++)
					{

						for (int j = 0; j < gameObject[layerJ].size(); j++)
						{
							
							checkObjectCollision(gameObject[layerI][i], gameObject[layerJ][j]);
							
						}

					}

				}

			}
		}		
	}
}

void ObjectManager::clearDeadObject()
{
	for (int j = 0; j < 10; j++)
	{
		/////////////////////삭제로..표시된...객체를 제거함///////////
		for (int i = 0; i < gameObject[j].size(); i++)
		{
			if (gameObject[j][i]->getIsDead() == true)  //삭제로..표시된 객체
			{
				GameObject* o = gameObject[j][i];

				//stl vector 목록에서 제거
				gameObject[j].erase(gameObject[j].begin() + i);
				i--;

				//게임오브젝트에...객체가 destroy됨을 알림
				o->onDestroy();

				//객체 delete 하기
				delete o;
			}
		}
	}
}

void ObjectManager::draw()
{
	for (int j = 0; j < 10; j++)
	{
		for (int i = 0; i < gameObject[j].size(); i++)
		{
			gameObject[j][i]->draw();          //이미지 그리기
			gameObject[j][i]->onDrawGizmos();  //기즈모 그리기
		}
	}
}

void ObjectManager::clear()
{
	for (int j = 0; j < 10; j++)
	{
		for (int i = 0; i < gameObject[j].size(); i++)
		{
			delete gameObject[j][i];
		}

		//j번째 ... stl vector 를 clear해서..저장공간을 모두 제거함
		gameObject[j].clear();
	}
}