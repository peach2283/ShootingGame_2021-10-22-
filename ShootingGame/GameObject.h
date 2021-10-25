#pragma once

#include <iostream>
#include <string>

using namespace std;

class GameObject
{
private:
	//�⺻�Ӽ�//
	string tag;
	string name;
	bool active;

	//Ʈ������//
	float px;
	float py;

	//��Ÿ �Ӽ�//
public:
	//������, �Ҹ���
	GameObject(string tag, string name, bool active, float px, float py);
	virtual ~GameObject();  //���������� �θ� Ŭ������ �Ҹ��ڴ� �׻� ��������..�ۼ���

	//����, ��Ÿ
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

	//�⺻ �����Լ�
	virtual void start();
	virtual void update();
	virtual void draw();

	//��Ÿ �Լ�//
	void translate(float x, float y);
};
