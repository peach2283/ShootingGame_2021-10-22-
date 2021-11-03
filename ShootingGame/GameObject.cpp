
#include "framework.h"
#include "ShootingGame.h"

//������, �Ҹ���
GameObject::GameObject(string tag, string name, bool active, float px, float py)
{
	this->tag		= tag;
	this->name		= name;
	this->active	= active;

	this->px = px;
	this->py = py;

	this->collider = nullptr;
}

GameObject::~GameObject()
{
	cout << "---�θ� GameObject �Ҹ���---" << endl;
}

//����, ��Ÿ
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

void GameObject::start()
{}

void GameObject::update()
{}

void GameObject::draw()
{}

void GameObject::translate(float x, float y)
{
	px = px + x;
	py = py + y;
}

void GameObject::addBoxCollider2D(BoxCollider2D* box)
{
	collider = box;
}