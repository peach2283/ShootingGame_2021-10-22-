#pragma once

class Time
{
private:
	static float startTime;
	static float endTime;	
public:
	static void  init();
	static void  update();

	static float deltaTime; //����Ƽ�� �����ϰ�..����ϱ� ���ؼ�..public���� �����ϵ�����
};