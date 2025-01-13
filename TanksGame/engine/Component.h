#pragma once


class Actor;


class Component
{
public:
	Component(Actor* owner);
	~Component();
	Component(Component& other) = default;

	bool GetStarted() { return m_started; };
	Actor* GetOwner() { return m_owner; };
	void SetOwner(Actor* owner) { m_owner = owner; };
	bool GetEnabled() { return m_enabled; };
	void SetEnabled(bool value);

	void Start() { m_started = true; };
	void Update(double deltaTime) {};
	void End() {};
	
private:
	Actor* m_owner;
	bool m_started;
	bool m_enabled;

	void OnEnable();
	void OnDisable();
};
