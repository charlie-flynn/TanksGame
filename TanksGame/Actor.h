#pragma once
#include "Vector2.h"

typedef MathLibrary::Vector2 Vec2;

class Transform2D;
class Component;

class Actor 
{
public:
	Actor();
public:
	~Actor();
	void Instantiate(Actor *actor, Transform2D *transform,  Vec2 position, float rotation);
	void Destroy(Actor* actor);
	void OnEnable();
	void OnDisable();
	void Start();
	void Update();
	void End();
	void OnCollision(Actor* other);
	// commenting out the component functions to do later
	/*
	AddComponent
	RemoveComponent
	GetComponent
	GetComponents
	*/

private:
	Transform2D *m_transform;
	bool m_started;
	bool m_enabled;

	// other component functions to do later
	/*
	AddComponentToRemove
	RemoveComponentsToBeRemoved
	*/
};
