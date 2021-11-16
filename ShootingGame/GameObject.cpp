
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

	this->lifeTime    = 0;
	this->useLifeTime = false;
}

GameObject::~GameObject()
{
	//충돌체..제거하기
	for (int i = 0; i < collider.size(); i++)
	{
		BoxCollider2D* c = collider[i];
		delete c;
	}

	collider.clear();
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

float GameObject::getLifeTime()
{
	return lifeTime;
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
	//새로운 좌표까지의 이동량
	float dx = px - this->px;  //px = dx + this->px;

	//게임오브젝트..좌표지정//
	this->px = px;

	//충돌체의..좌표를 이동//
	for (int i = 0; i < collider.size(); i++)
	{
		collider[i]->translate(dx, 0);
	}
}

void GameObject::setPy(float py)
{
	float dy = py - this->py;

	this->py = py;

	for (int i = 0; i < collider.size(); i++)
	{
		collider[i]->translate(0, dy);
	}
}

void GameObject::setIsDead(bool isDead)
{
	this->isDead = isDead;
}

void GameObject::setLifeTime(float lifeTime)
{
	this->lifeTime    = lifeTime; //라이프타임 시간
	this->useLifeTime = true;     //라이프타임 사용함
}

void GameObject::start()
{}

void GameObject::update()
{}

void GameObject::draw()
{}

void GameObject::onDrawGizmos()
{
	for(int i=0 ; i < collider.size() ; i++)
	{
		//2D BoxCollider 그리기//
		float x, y, width, height;

		collider[i]->getBoudingBox(x, y, width, height);

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
	for(int i=0 ; i < collider.size() ; i++)
	{
		collider[i]->translate(x, y);
	}
}

void GameObject::addBoxCollider2D(BoxCollider2D* box)
{
	//박스의 원점을..게임오브젝트의..원점과 같아지도록..박스를 이동시키기//
	box->translate(px, py);
	
	//박스 추가하기
	collider.push_back(box);
}

vector<BoxCollider2D*> GameObject::getCollider()
{
	return collider; 
}

void GameObject::onTrigger(GameObject * other)
{
}

void GameObject::onDestroy()
{}

void GameObject::instantiate(GameObject* o)
{
	ObjectManager::instantiate(o);
}

void GameObject::destroy(GameObject* o)
{
	ObjectManager::destroy(o);
}

void GameObject::destroy(GameObject* o, float lifeTime)
{
	ObjectManager::destroy(o, lifeTime);
}

void GameObject::subLifeTime()
{
	if (useLifeTime == true)
	{
		lifeTime = lifeTime - Time::deltaTime;  //라이프타임 줄이기

		if (lifeTime <= 0)  //라이프타임이 모두 지남
		{
			this->isDead = true;  //제거 대상으로..표시함
		}
	}
}