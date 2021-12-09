
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

	this->parent = nullptr;
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

	//자식객체들로..active 상태 적용하기//
	for (int i = 0; i < childObject.size(); i++)
	{
		childObject[i]->setActive(active);
	}
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

	//자식객체..좌표를 이동//
	for (int i = 0; i < childObject.size(); i++)
	{
		childObject[i]->translate(dx, 0);
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

	for (int i = 0; i < childObject.size(); i++)
	{
		childObject[i]->translate(0, dy);
	}
}

void GameObject::setIsDead(bool isDead)
{
    //게임오브젝트..제거 표시	
	this->isDead = isDead;

	//자식객체들도..제거표시함
	for (int i = 0; i < childObject.size(); i++)
	{
		childObject[i]->setIsDead(isDead);
	}
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

	//자식오브젝트...이동시키기//
	for (int i = 0; i < childObject.size(); i++)
	{
		childObject[i]->translate(x, y);
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

void GameObject::addChildObject(GameObject* obj, int layer)
{
	//this, childObject목록체..obj가 자식으로..추가됨...
	obj->parent = this;
	obj->translate(px, py);

	childObject.push_back(obj);  //자식목록에..추가하기
	instantiate(obj, layer);     //ObjectManager에 추가하기
}

void GameObject::onTrigger(GameObject * other)
{
}

void GameObject::onDestroy()
{}

GameObject * GameObject::instantiate(GameObject* o, int layer)
{
	ObjectManager::instantiate(o, layer);
	return o;
}

void GameObject::destroy(GameObject* o)
{
	if (o->parent == nullptr)
	{
		//[1]삭제 객체가 자식이 아닌경우
		ObjectManager::destroy(o);
	}
	else {
		//[2]삭제 객체가 자식인 경우
		//(1)부모객체의 자식목록에서..제거
		for (int i = 0; i < o->parent->childObject.size(); i++)
		{
			if (o->parent->childObject[i] == o)
			{
				o->parent->childObject.erase( o->parent->childObject.begin() + i);
				i--;
			}
		}

		//(2)오브젝트매니저에서..삭제하기
		ObjectManager::destroy(o);
	}
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

GameObject* GameObject::find(string name)
{
	for (int i = 0; i < childObject.size(); i++)
	{
		if (childObject[i]->getName() == name)
		{
			return childObject[i];
		}
	}

	//이름으로..자식객체를 찾지못함//
	return nullptr;
}

int GameObject::childCount()
{
	return childObject.size();
}