#include "framework.h"
#include "ShootingGame.h"

Shield::Shield(float px, float py) : Animation("����", "", true, px, py)
{}

Shield::~Shield()
{}

void Shield::start()
{
	//���� �ִϸ��̼� �̹��� �߰�
	addImage("Asset/��ȣ����1.bmp", 0);
	addImage("Asset/��ȣ����2.bmp", 0);
	addImage("Asset/��ȣ����3.bmp", 0);

	//�浹ü �߰�
	addBoxCollider2D(new BoxCollider2D(0, 0, 90, 90));
}