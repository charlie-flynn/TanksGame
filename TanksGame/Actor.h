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
	static Actor Instantiate(Actor& actor, Transform2D* transform, const Vec2 position, const float rotation);
	void Destroy(Actor* actor);
	void Start();
	void Update();
	void End();
	void OnCollision(Actor* other);
	bool GetStarted() { return m_started; };
	bool GetEnabled() { return m_enabled; };
	void SetEnabled(const bool value);
	Transform2D* GetTransform();
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
	Transform2D GetTransformDereferenced();
	// make sure to have component lists when you inevitably make components

	// other component functions to do later
	/*
	AddComponentToRemove
	RemoveComponentsToBeRemoved
	*/
};
