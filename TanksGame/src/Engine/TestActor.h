#pragma once
#include "Engine/Actor.h"

class SquareCollider;

class TestActor : public Actor
{

public:
	TestActor();
	void Destroy(Actor* actor);
	void Start() override;
	void Update(double deltaTime) override;
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

	SquareCollider* m_collider;

	void OnEnable() override;
	void OnDisable() override;
	// make sure to have component lists when you inevitably make components

	// other component functions to do later
	/*
	AddComponentToRemove
	RemoveComponentsToBeRemoved
	*/

};
