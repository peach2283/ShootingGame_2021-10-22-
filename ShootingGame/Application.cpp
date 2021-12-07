#include "framework.h"
#include "ShootingGame.h"

bool Application::isPlaying = true;

void Application::quit()
{
	isPlaying = false;
}

bool Application::getIsPlaying()
{
	return isPlaying;
}