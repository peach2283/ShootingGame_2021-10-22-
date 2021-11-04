#pragma once
#include <vector>
#include "GameObject.h"

using namespace std;

class ObjectManager
{
private:
	static vector<GameObject* > gameObject;

public:
	
	//gameObject STL vector에...객체 추가하기함수//
	static void instantiate(GameObject* o);

	//gameObject STL vector에..추가된 객체 업데이트/그리기/삭제하기 함수//
	static void update();
	static void checkCollision();
	static void draw();
	static void clear();
};