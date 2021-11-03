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