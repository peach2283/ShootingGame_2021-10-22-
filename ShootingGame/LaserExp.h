#pragma once

#include "Animation.h"

class LaserExp : public Animation
{
private:
public:
	LaserExp(float px, float py);
	~LaserExp();

	void start();

	//애니메이션 이베튼 함수 오버라이딩//
	void onAnimationEnd();
};
