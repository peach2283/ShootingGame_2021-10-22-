#pragma once
#include <vector>
#include "GameObject.h"

using namespace std;

class ObjectManager
{
private:
	static vector<GameObject* > gameObject;

public:
	
	//gameObject STL vector��...��ü �߰��ϱ��Լ�//
	static void instantiate(GameObject* o);

	//gameObject STL vector��..�߰��� ��ü ������Ʈ/�׸���/�����ϱ� �Լ�//
	static void update();
	static void draw();
	static void clear();
};