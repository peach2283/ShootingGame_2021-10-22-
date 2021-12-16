#pragma once

class Scene
{
private:
public:
	Scene();
	~Scene();

	virtual void load();
	void run();
	void unload();
};
