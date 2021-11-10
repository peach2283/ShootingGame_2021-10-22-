#pragma once
#include <vector>
#include "GameObject.h"

using namespace std;

class ObjectManager
{
private:
	static vector<GameObject* > gameObject;

public:
	
	//gameObject STL vector��...��ü �߰� /���� �ϱ��Լ�//
	static void instantiate(GameObject* o);

	static void destroy(GameObject* o);
	static void destroy(GameObject* o, float lifeTime);

	//gameObject STL vector��..�߰��� ��ü ������Ʈ/�׸���/�����ϱ� �Լ�//
	static void update();
	static void checkLifeTime();
	static void checkCollision();
	static void clearDeadObject();
	static void draw();
	static void clear();
};