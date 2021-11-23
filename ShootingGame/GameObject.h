#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "BoxCollider2D.h"

using namespace std;

class GameObject
{
private:
	//기본속성//
	string tag;
	string name;
	bool active;

	//트랜스폼//
	float px;
	float py;

	//라이프 타임
	float lifeTime;

	//라이프 타임 사용 여부 지정변수
	bool useLifeTime;  //true 는 사용, false 는 사용안함

	//객체가 삭제대상인지를 표시하는 변수
	bool isDead;  //true(삭제 대상임), false(삭제대상 아님)

	//2D 박스콜라이더 목록//
	vector<BoxCollider2D*> collider;

	//게임오브젝트 목록//
	vector<GameObject*> childObject;

	//부목 객체를 저장하는 변수
	GameObject* parent;

public:
	//생성자, 소멸자
	GameObject(string tag, string name, bool active, float px, float py);
	virtual ~GameObject();  //다형성에서 부모 클래스의 소멸자는 항상 가상으로..작성함

	//게터, 세타
	string getTag();
	string getName();
	bool   getActive();

	float getPx();
	float getPy();
	bool  getIsDead();
	float getLifeTime();

	void setTag(string tag);
	void setName(string name);
	void setActive(bool active);

	void setPx(float px);
	void setPy(float py);
	void setIsDead(bool isDead);
	void setLifeTime(float lifeTime);

	//기본 가상함수
	virtual void start();
	virtual void update();
	virtual void draw();

	//기즈모..그리기 함수
	virtual void onDrawGizmos();

	//기타 함수//
	void translate(float x, float y);

	//2D 충돌체 추가함수//
	void addBoxCollider2D(BoxCollider2D* box);

	//2D 충돌체 게터
	vector<BoxCollider2D *> getCollider();

	//자식오브젝트 추가함수//
	void addChidObject(GameObject* obj, int layer=0);

	//충돌(Trigger) 이벤트 가상 함수
	virtual void onTrigger(GameObject * other);

	//제거(Destroy) 이벤트 
	virtual void onDestroy();

	//객체 생성 및 제거함수
	void instantiate(GameObject* o, int layer=0);
	void destroy(GameObject* o);
	void destroy(GameObject* o, float lifeTime);

	//라이프타임 줄이기 함수
	void subLifeTime();

	//이름으로 자식객체 찾기
	GameObject* find(string name);
};
