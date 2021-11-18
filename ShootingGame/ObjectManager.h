#pragma once
#include <vector>
#include "GameObject.h"

using namespace std;

class ObjectManager
{
private:
	static vector<GameObject* > gameObject[10]; //0, 1, 2, ....., 9 까지의 게임객체 .. 목록(레이어)

public:
	
	//gameObject STL vector에...객체 추가 /삭제 하기함수//
	static void instantiate(GameObject* o, int layer=0); //레이어가 생략되면.. 0 번 사용

	static void destroy(GameObject* o);
	static void destroy(GameObject* o, float lifeTime);

	//gameObject STL vector에..추가된 객체 업데이트/그리기/삭제하기 함수//
	static void update();
	static void checkLifeTime();
	static void checkCollision();
	static void clearDeadObject();
	static void draw();
	static void clear();
};