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
	//���� ��ü�� .. �浹���Ŀ� �����Ǿ�� �Ѵٴ�..������ ǥ���ϰ�..�浹���Ŀ�..������ ������
	o->setIsDead(true);
}

void ObjectManager::destroy(GameObject* o, float lifeTime)
{
	//�ٷλ����ϱ� �ʰ�...lifetime�� ������..��ü�� ������
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

void ObjectManager::checkCollision()
{
	//�浹�˻� ���̾�� �����//
	for (int layerI = 0; layerI < 10; layerI++)
	{
		for (int layerJ = 0; layerJ < 10; layerJ++)
		{
			if (layerI <= layerJ)
			{
			
				////////////////���� ���̾���..���ӿ�����Ʈ����..�浹�˻�///////////
				if (layerI == layerJ)
				{









					for (int i = 0; i < gameObject[layerI].size(); i++)
					{
						for (int j = 0; j < gameObject[layerJ].size(); j++)
						{
							if (i < j)
							{
								GameObject* objI = gameObject[layerI][i];  //layerI���� i ��°...���ӿ�����Ʈ
								GameObject* objJ = gameObject[layerJ][j];  //layerJ���� j ��°...���ӿ�����Ʈ

								vector<BoxCollider2D*> colI = objI->getCollider();
								vector<BoxCollider2D*> colJ = objJ->getCollider();

								for (int ii = 0; ii < colI.size(); ii++)
								{
									for (int jj = 0; jj < colJ.size(); jj++)
									{
										//colI[ii]  �浹ü�� colJ[jj] �浹ü��...�浹�˻縦 �ǽ���
										//�浹 �ڽ� ��ǥ ���ϱ�//
										float x, y, width, height;
										float x0I, y0I, x1I, y1I;    //objI(colI)�� �ڽ� �浹ü ��ǥ
										float x0J, y0J, x1J, y1J;    //objJ(colJ)�� �ڽ� �浹ü ��ǥ

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
											//objI �ϰ� objJ ... ���ӿ�����Ʈ�� �浹��
											objI->onTrigger(objJ); //objI�� �Լ��� �̿��ؼ�..objJ�� �浹(Trigger)�� �߻�������..�˸�
											objJ->onTrigger(objI); //objJ�� �Լ��� �̿��ؼ�..objI�� �浹(Trigger)�� �߻�������..�˸�
										}
									}
								}
							}
						}
					}







				
				}
				else //////////�ٸ� ���̾���..���ӿ�����Ʈ����...�浹�˻�//////////
				{







					for (int i = 0; i < gameObject[layerI].size(); i++)
					{
						for (int j = 0; j < gameObject[layerJ].size(); j++)
						{
							
								GameObject* objI = gameObject[layerI][i];  //layerI���� i ��°...���ӿ�����Ʈ
								GameObject* objJ = gameObject[layerJ][j];  //layerJ���� j ��°...���ӿ�����Ʈ

								vector<BoxCollider2D*> colI = objI->getCollider();
								vector<BoxCollider2D*> colJ = objJ->getCollider();

								for (int ii = 0; ii < colI.size(); ii++)
								{
									for (int jj = 0; jj < colJ.size(); jj++)
									{
										//colI[ii]  �浹ü�� colJ[jj] �浹ü��...�浹�˻縦 �ǽ���
										//�浹 �ڽ� ��ǥ ���ϱ�//
										float x, y, width, height;
										float x0I, y0I, x1I, y1I;    //objI(colI)�� �ڽ� �浹ü ��ǥ
										float x0J, y0J, x1J, y1J;    //objJ(colJ)�� �ڽ� �浹ü ��ǥ

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
											//objI �ϰ� objJ ... ���ӿ�����Ʈ�� �浹��
											objI->onTrigger(objJ); //objI�� �Լ��� �̿��ؼ�..objJ�� �浹(Trigger)�� �߻�������..�˸�
											objJ->onTrigger(objI); //objJ�� �Լ��� �̿��ؼ�..objI�� �浹(Trigger)�� �߻�������..�˸�
										}
									}
								}
							
						}
					}









				}







			}
		}		
	}

	/************************************************
	***************************************************/
}

void ObjectManager::clearDeadObject()
{
	for (int j = 0; j < 10; j++)
	{
		/////////////////////������..ǥ�õ�...��ü�� ������///////////
		for (int i = 0; i < gameObject[j].size(); i++)
		{
			if (gameObject[j][i]->getIsDead() == true)  //������..ǥ�õ� ��ü
			{
				GameObject* o = gameObject[j][i];

				//stl vector ��Ͽ��� ����
				gameObject[j].erase(gameObject[j].begin() + i);
				i--;

				//���ӿ�����Ʈ��...��ü�� destroy���� �˸�
				o->onDestroy();

				//��ü delete �ϱ�
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
			gameObject[j][i]->draw();          //�̹��� �׸���
			gameObject[j][i]->onDrawGizmos();  //����� �׸���
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

		//j��° ... stl vector �� clear�ؼ�..��������� ��� ������
		gameObject[j].clear();
	}
}