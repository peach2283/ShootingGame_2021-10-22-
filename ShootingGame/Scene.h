#pragma once

class Scene
{
private:
	string name;

public:
	Scene(string name);
	~Scene();

	virtual void load();
	void run();
	void unload();

	string getName();
};
