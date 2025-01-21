#pragma once
#include "DynamicArray.h"
#include "vector2.h"

typedef MathLibrary::Vector2 Vec2;

class Transform2D;
class Component;
class Collider;

class Actor 
{
public:
	Actor(char const* name = "Actor");
public:
	~Actor();
	static Actor* Instantiate(Actor* actor, Transform2D* transform, const Vec2 position, const float rotation);
	void Destroy(Actor* actor);
	void virtual Start();
	void virtual Update(double deltaTime);
	void virtual End() {};
	void virtual OnCollision() {};
	bool GetStarted() { return m_started; };
	bool GetEnabled() { return m_enabled; };
	void SetEnabled(const bool value);
	Transform2D* GetTransform();
	virtual Collider* GetCollider() { return nullptr; };
	char const* GetName() { return m_name; };

	template <typename T>
	T* AddComponent(T* component);
	template <typename T>
	T* AddComponent();
	template <typename T>
	void RemoveComponent(T component);

	// deprecated functions because i genuinely could not get these to work to save my life
	/*
	template <typename T>
	void RemoveComponent();
	template <typename T>
	Component* GetComponent();
	template <typename T>
	Component* GetComponents();
	*/

private:
	Transform2D* m_transform;
	const char* m_name;

	bool m_started;
	bool m_enabled;

	DynamicArray<Component*> m_components;

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
inline T* Actor::AddComponent(T* component)
{
	m_components.Add((Component*)component);
	return component;
}

template<typename T>
inline T* Actor::AddComponent()
{
	return AddComponent<T>(new T(this));
}

template<typename T>
inline void Actor::RemoveComponent(T component)
{
	m_components.Remove((Component*)component);
	return;
}

/*
template<typename T>
inline void Actor::RemoveComponent()
{
	T component = GetComponent<T>();
	if (component != nullptr)
		RemoveComponent(component);
	return;
}

template<typename T>
inline Component* Actor::GetComponent()
{
	// this doesnt work lol.
	for (int i = 0; i < m_components.Length(); i++)
	{

	}
	return nullptr;
}

template<typename T>
inline Component* Actor::GetComponents()
{
	int length = 0;
	T* components = T[m_components.Length()];

	for (int i = 0; i < m_components.Length(); i++)
	{
		if (typeid(m_components[i] == typeid(T)))
		{
			components[length] = m_components[i];
			length++;
		}
	}

	return components;
}
*/
