#pragma once
#include "DynamicArray.h"
#include "vector2.h"

class Transform2D;
class Component;

typedef MathLibrary::Vector2 Vec2;

class Actor 
{
public:
	Actor();
	~Actor();
	static Actor* Instantiate(Actor* actor, Transform2D* transform, const Vec2 position, const float rotation);
	void Destroy(Actor* actor);
	void virtual Start();
	void virtual Update(double deltaTime) {};
	void virtual End() {};
	void virtual OnCollision(Actor* other) {};
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

	template <typename T>
	T* AddComponent(T component);
	template <typename T>
	T* AddComponent();
	template <typename T>
	void RemoveComponent(T component);
	template <typename T>
	void RemoveComponent();
	template <typename T>
	T* GetComponent();
	template <typename T>
	T* GetComponents();

private:
	Transform2D* m_transform;

	bool m_started;
	bool m_enabled;

	DynamicArray<Component> m_components;

	void virtual OnEnable() {};
	void virtual OnDisable() {};
	// make sure to have component lists when you inevitably make components

	// other component functions to do later (we might not need these ?)
	/*
	AddComponentToRemove
	RemoveComponentsToBeRemoved
	*/
};

template<typename T>
inline T* Actor::AddComponent(T component)
{
	m_components.Add(component);
	return nullptr;
}

template<typename T>
inline T* Actor::AddComponent()
{
	return AddComponent(new T(this));
}

template<typename T>
inline void Actor::RemoveComponent(T component)
{
	m_components.Remove(component);
	return;
}

template<typename T>
inline void Actor::RemoveComponent()
{
	T component = GetComponent<T>();
	if (component != nullptr)
		RemoveComponent(component);
	return;
}

template<typename T>
inline T* Actor::GetComponent()
{
	for (int i = 0; i < m_components.Length(); i++)
	{
		if (typeid(m_components[i]) = typeid(T))
			return m_components[i];
	}
	return nullptr;
}

template<typename T>
inline T* Actor::GetComponents()
{


	return nullptr;
}
