
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

void GameObject::onDrawGizmos()
{
	if (collider != nullptr)
	{
		//2D BoxCollider �׸���//
		float x, y, width, height;

		collider->getBoudingBox(x, y, width, height);

		//�簢�� ������ ���
		float x0 = x, y0 = y;
		float x1 = x0 + width, y1 = y0 + height;

		drawRect(x0, y0, x1, y1, 255, 0, 0);
	}
}

void GameObject::translate(float x, float y)
{
	//���ӿ�����Ʈ �̵�//
	px = px + x;
	py = py + y;

	//�浹ü..�̵���Ű��//
	if (collider != nullptr)
	{
		collider->translate(x, y);
	}
}

void GameObject::addBoxCollider2D(BoxCollider2D* box)
{
	//�ڽ��� ������..���ӿ�����Ʈ��..������ ����������..�ڽ��� �̵���Ű��//
	box->translate(px, py);
	
	//�ڽ� �߰��ϱ�
	collider = box;
}

BoxCollider2D* GameObject::getCollider()
{
	return collider;
}