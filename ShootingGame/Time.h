#pragma once

class Time
{
private:
	static float startTime;
	static float endTime;	
public:
	static void  init();
	static void  update();

	static float deltaTime; //유니티와 유사하게..사용하기 위해서..public으로 접근하도록함
};