#pragma once
#include "Actor.h"
#include "DynamicArray.h"

class Scene
{

private:
	Scene(const DynamicArray<Actor>& _actors);

public:
	~Scene();
	void AddActor(Actor& actor);
	bool RemoveActor(Actor& actor);
	virtual void Start();
	virtual void Update(double deltatime);
	virtual void End();
};