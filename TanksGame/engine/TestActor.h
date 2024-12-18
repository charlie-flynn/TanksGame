#pragma once
#include "Actor.h"


class TestActor : public Actor
{

public:
	TestActor();
	void Destroy(Actor* actor);
	void Start() override;
	void Update() override;
	void End() override;
	void OnCollision(Actor* other) override;
	// commenting out the component functions to do later
	/*
	AddComponent
	RemoveComponent
	GetComponent
	GetComponents
	*/

private:

	void OnEnable() override;
	void OnDisable() override;
	// make sure to have component lists when you inevitably make components

	// other component functions to do later
	/*
	AddComponentToRemove
	RemoveComponentsToBeRemoved
	*/

};
