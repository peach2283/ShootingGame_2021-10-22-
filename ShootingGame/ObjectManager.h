#pragma once
#include <vector>
#include "GameObject.h"

using namespace std;

class ObjectManager
{
private:
	static vector<GameObject* > gameObject[10]; //0, 1, 2, ....., 9 ������ ���Ӱ�ü .. ���(���̾�)

public:
	
	//gameObject STL vector��...��ü �߰� /���� �ϱ��Լ�//
	static void instantiate(GameObject* o, int layer=0); //���̾ �����Ǹ�.. 0 �� ���

	static void destroy(GameObject* o);
	static void destroy(GameObject* o, float lifeTime);

	//gameObject STL vector��..�߰��� ��ü ������Ʈ/�׸���/�����ϱ� �Լ�//
	static void update();
	static void checkLifeTime();
	static void checkCollision();
	static void checkObjectCollision(GameObject* objI, GameObject* objJ);
	static void clearDeadObject();
	static void draw();
	static void clear();
};