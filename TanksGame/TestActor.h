#pragma once
#include "Actor.h"


class TestActor : public Actor
{

public:
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
	Transform2D* m_transform;
	bool m_started;
	bool m_enabled;

	void OnEnable();
	void OnDisable();
	// make sure to have component lists when you inevitably make components

	// other component functions to do later
	/*
	AddComponentToRemove
	RemoveComponentsToBeRemoved
	*/

};
