
#include "framework.h"
#include "ShootingGame.h"

//������, �Ҹ���
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
	//�浹ü..�����ϱ�
	for (int i = 0; i < collider.size(); i++)
	{
		BoxCollider2D* c = collider[i];
		delete c;
	}

	collider.clear();
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
	//���ο� ��ǥ������ �̵���
	float dx = px - this->px;  //px = dx + this->px;

	//���ӿ�����Ʈ..��ǥ����//
	this->px = px;

	//�浹ü��..��ǥ�� �̵�//
	for (int i = 0; i < collider.size(); i++)
	{
		collider[i]->translate(dx, 0);
	}

	//�ڽİ�ü..��ǥ�� �̵�//
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
    //���ӿ�����Ʈ..���� ǥ��	
	this->isDead = isDead;

	//�ڽİ�ü�鵵..����ǥ����
	for (int i = 0; i < childObject.size(); i++)
	{
		childObject[i]->setIsDead(isDead);
	}
}

void GameObject::setLifeTime(float lifeTime)
{
	this->lifeTime    = lifeTime; //������Ÿ�� �ð�
	this->useLifeTime = true;     //������Ÿ�� �����
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
		//2D BoxCollider �׸���//
		float x, y, width, height;

		collider[i]->getBoudingBox(x, y, width, height);

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
	for(int i=0 ; i < collider.size() ; i++)
	{
		collider[i]->translate(x, y);
	}

	//�ڽĿ�����Ʈ...�̵���Ű��//
	for (int i = 0; i < childObject.size(); i++)
	{
		childObject[i]->translate(x, y);
	}
}

void GameObject::addBoxCollider2D(BoxCollider2D* box)
{
	//�ڽ��� ������..���ӿ�����Ʈ��..������ ����������..�ڽ��� �̵���Ű��//
	box->translate(px, py);
	
	//�ڽ� �߰��ϱ�
	collider.push_back(box);
}

vector<BoxCollider2D*> GameObject::getCollider()
{
	return collider; 
}

void GameObject::addChidObject(GameObject* obj, int layer)
{
	//this, childObject���ü..obj�� �ڽ�����..�߰���...
	obj->parent = this;
	obj->translate(px, py);

	childObject.push_back(obj);  //�ڽĸ�Ͽ�..�߰��ϱ�
	instantiate(obj, layer);     //ObjectManager�� �߰��ϱ�
}

void GameObject::onTrigger(GameObject * other)
{
}

void GameObject::onDestroy()
{}

void GameObject::instantiate(GameObject* o, int layer)
{
	ObjectManager::instantiate(o, layer);
}

void GameObject::destroy(GameObject* o)
{
	if (o->parent == nullptr)
	{
		//[1]���� ��ü�� �ڽ��� �ƴѰ��
		ObjectManager::destroy(o);
	}
	else {
		//[2]���� ��ü�� �ڽ��� ���
		//(1)�θ�ü�� �ڽĸ�Ͽ���..����
		for (int i = 0; i < o->parent->childObject.size(); i++)
		{
			if (o->parent->childObject[i] == o)
			{
				o->parent->childObject.erase( o->parent->childObject.begin() + i);
				i--;
			}
		}

		//(2)������Ʈ�Ŵ�������..�����ϱ�
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
		lifeTime = lifeTime - Time::deltaTime;  //������Ÿ�� ���̱�

		if (lifeTime <= 0)  //������Ÿ���� ��� ����
		{
			this->isDead = true;  //���� �������..ǥ����
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

	//�̸�����..�ڽİ�ü�� ã������//
	return nullptr;
}