#pragma once

class BoxCollider2D
{
private:
	//�簢�� ����Ÿ//
	float x, y;
	float width, height;
public:
	BoxCollider2D(float x, float y, float width, float height);
	virtual ~BoxCollider2D();
	
	void getBoudingBox(float& x, float& y, float& width, float& height);
	void translate(float x, float y);
};