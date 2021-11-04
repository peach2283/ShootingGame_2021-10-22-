#pragma once

#include <iostream>
#include <string>
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

	//2D 박스콜라이더 목록//
	BoxCollider2D* collider;

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

	void setTag(string tag);
	void setName(string name);
	void setActive(bool active);

	void setPx(float px);
	void setPy(float py);

	//기본 가상함수
	virtual void start();
	virtual void update();
	virtual void draw();

	//기즈모..그리기 함수
	void onDrawGizmos();

	//기타 함수//
	void translate(float x, float y);

	//2D 충돌체 추가함수//
	void addBoxCollider2D(BoxCollider2D* box);

	//2D 충돌체 게터
	BoxCollider2D * getCollider();
};
