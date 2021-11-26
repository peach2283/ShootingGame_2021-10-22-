#include "framework.h"
#include "ShootingGame.h"

Boss::Boss(float px, float py) : Sprite("","",true, px, py)
{}

Boss::~Boss()
{}

void Boss::start()
{
	//���� �⺻�̹��� �ε� �ϱ�//
	setImage("Asset/����.bmp", 0, 0, 493, 206);

	//���� ������ �̹��� �ε��ϱ�//
	//setImage("Asset/����.bmp", 0, 613, 385, 182);

	//�����緯..�ڽİ�ü �߰��ϱ�//
	addChidObject(new Propeller( 63, 41));
	addChidObject(new Propeller(111, 41));
	addChidObject(new Propeller(159, 41));

	addChidObject(new Propeller(302, 41));
	addChidObject(new Propeller(350, 41));
	addChidObject(new Propeller(398, 41));

	//���� �ڽİ�ü �߰��ϱ�//
	addChidObject(new Wing(256, 97 , 0 )); //������ ù��°
	addChidObject(new Wing(302, 94,  1 )); //������ �ι�°
	addChidObject(new Wing(350, 90,  2 )); //������ ����°
	addChidObject(new Wing(405, 84,  3 )); //������ �׹�°

}