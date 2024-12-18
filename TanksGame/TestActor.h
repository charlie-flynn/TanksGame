#pragma once
#include "Actor.h"


class TestActor : public Actor
{

public:
	TestActor();
	void Destroy(Actor* actor);
	void Start();
	void Update();
	void End();
	void OnCollision(Actor* other);
	void SetEnabled(const bool value);
	// commenting out the component functions to do later
	/*
	AddComponent
	RemoveComponent
	GetComponent
	GetComponents
	*/

private:

	void OnEnable();
	void OnDisable();
	// make sure to have component lists when you inevitably make components

	// other component functions to do later
	/*
	AddComponentToRemove
	RemoveComponentsToBeRemoved
	*/

};
