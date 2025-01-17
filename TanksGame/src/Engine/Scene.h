#pragma once
#include "Actor.h"
#include "DynamicArray.h"
#include <string>

class Scene
{

private:

	 DynamicArray<Actor*> m_actors;

public:
	Scene();
	~Scene();
	void AddActor(Actor& actor);
	void RemoveActor(Actor* actor);
	virtual void Start();
	virtual void Update(double deltatime);
	virtual void End();
};