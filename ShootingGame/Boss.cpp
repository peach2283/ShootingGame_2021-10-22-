#include "framework.h"
#include "ShootingGame.h"

Boss::Boss(float px, float py) : Sprite("","",true, px, py)
{}

Boss::~Boss()
{}

void Boss::start()
{
	//보스 기본이미지 로드 하기//
	setImage("Asset/보스.bmp", 0, 0, 493, 206);

	//보스 폭발후 이미지 로드하기//
	//setImage("Asset/보스.bmp", 0, 613, 385, 182);

	//프로펠러..자식객체 추가하기//
	addChidObject(new Propeller( 63, 41));
	addChidObject(new Propeller(111, 41));
	addChidObject(new Propeller(159, 41));

	addChidObject(new Propeller(302, 41));
	addChidObject(new Propeller(350, 41));
	addChidObject(new Propeller(398, 41));

	//날개 자식객체 추가하기//
	addChidObject(new Wing(256, 97 , 0 )); //오른쪽 첫번째
	addChidObject(new Wing(302, 94,  1 )); //오른쪽 두번째
	addChidObject(new Wing(350, 90,  2 )); //오른쪽 세번째
	addChidObject(new Wing(405, 84,  3 )); //오른쪽 네번째

}