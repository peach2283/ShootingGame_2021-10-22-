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
	addChildObject(new Propeller( 63, 41));
	addChildObject(new Propeller(111, 41));
	addChildObject(new Propeller(159, 41));

	addChildObject(new Propeller(302, 41));
	addChildObject(new Propeller(350, 41));
	addChildObject(new Propeller(398, 41));

	//날개 자식객체 추가하기//
	addChildObject(new Wing(256, 97 , 0 )); //오른쪽 첫번째
	addChildObject(new Wing(302, 94,  1 )); //오른쪽 두번째
	addChildObject(new Wing(350, 90,  2 )); //오른쪽 세번째
	addChildObject(new Wing(405, 84,  3 )); //오른쪽 네번째

	addChildObject(new Wing(206, 98,  4 )); //왼쪽 첫번째
	addChildObject(new Wing(158, 94,  5 )); //왼쪽 두번째
	addChildObject(new Wing(110, 90,  6 )); //왼쪽 세번째
	addChildObject(new Wing(62 , 84,  7 )); //왼쪽 네번째

	//보스 건 자식객체 추가하기//
	addChildObject(new Gun(94 , 71));
	addChildObject(new Gun(142, 71));
	addChildObject(new Gun(190, 71));

	addChildObject(new Gun(238, 63));

	addChildObject(new Gun(286, 71));
	addChildObject(new Gun(334, 71));
	addChildObject(new Gun(382, 71));

	//보스 대포 자식객체 추가하기
	addChildObject(new Cannon(265 + 5, 97 + 10));
	addChildObject(new Cannon(206 - 5, 97 + 10));

	//보스 레이더 자식객체 추가하기
	addChildObject(new Radar(241, 105));
	addChildObject(new Radar(241, 117));
}