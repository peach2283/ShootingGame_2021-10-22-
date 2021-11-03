#include "framework.h"
#include "ShootingGame.h"

BoxCollider2D::BoxCollider2D(float x, float y, float width, float height)
{
	this->x = x;
	this->y = y;

	this->width  = width;
	this->height = height;
}

BoxCollider2D::~BoxCollider2D()
{}

void BoxCollider2D::getBoudingBox(float& x, float& y, float& width, float& height)
{
	x = this->x;
	y = this->y;

	width  = this->width;
	height = this->height;
}

void BoxCollider2D::translate(float x, float y)
{
	this->x +=  x;
	this->y +=  y;
}