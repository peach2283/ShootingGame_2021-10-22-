
#include "framework.h"
#include "ShootingGame.h"

//생성자, 소멸자
GameObject::GameObject(string tag, string name, bool active, float px, float py)
{
	this->tag	 = tag;
	this->name	 = name;
	this->active = active;
	this->isDead = false;

	this->px = px;
	this->py = py;

	this->collider = nullptr;
}

GameObject::~GameObject()
{
}

//게터, 세타
string GameObject::getTag()
{
	return tag;
}

string GameObject::getName()
{
	return name;
}

bool  GameObject::getActive()
{
	return active;
}

float GameObject::getPx()
{
	return px;
}

float GameObject::getPy()
{
	return py;
}

bool GameObject::getIsDead()
{
	return isDead;
}

void GameObject::setTag(string tag)
{
	this->tag = tag;
}

void GameObject::setName(string name)
{
	this->name = name;
}

void GameObject::setActive(bool active)
{
	this->active = active;
}

void GameObject::setPx(float px)
{
	this->px = px;
}

void GameObject::setPy(float py)
{
	this->py = py;
}

void GameObject::setIsDead(bool isDead)
{
	this->isDead = isDead;
}

void GameObject::start()
{}

void GameObject::update()
{}

void GameObject::draw()
{}

void GameObject::onDrawGizmos()
{
	if (collider != nullptr)
	{
		//2D BoxCollider 그리기//
		float x, y, width, height;

		collider->getBoudingBox(x, y, width, height);

		//사각형 꼭지점 계산
		float x0 = x, y0 = y;
		float x1 = x0 + width, y1 = y0 + height;

		drawRect(x0, y0, x1, y1, 255, 0, 0);
	}
}

void GameObject::translate(float x, float y)
{
	//게임오브젝트 이동//
	px = px + x;
	py = py + y;

	//충돌체..이동시키기//
	if (collider != nullptr)
	{
		collider->translate(x, y);
	}
}

void GameObject::addBoxCollider2D(BoxCollider2D* box)
{
	//박스의 원점을..게임오브젝트의..원점과 같아지도록..박스를 이동시키기//
	box->translate(px, py);
	
	//박스 추가하기
	collider = box;
}

BoxCollider2D* GameObject::getCollider()
{
	return collider;
}

void GameObject::onTrigger(GameObject * other)
{
}

void GameObject::instantiate(GameObject* o)
{
	ObjectManager::instantiate(o);
}

void GameObject::destroy(GameObject* o)
{
	ObjectManager::destroy(o);
}