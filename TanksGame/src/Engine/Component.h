#pragma once


class Actor;


class Component
{
public:
	Component(Actor* owner = nullptr);
	~Component();
	Component(Component& other);

	bool GetStarted() { return m_started; };
	Actor* GetOwner() { return m_owner; };
	void SetOwner(Actor* owner) { m_owner = owner; };
	bool GetEnabled() { return m_enabled; };
	void SetEnabled(bool value);

	virtual void Start() { m_started = true; };
	virtual void Update(double deltaTime) {};
	virtual void End() {};
	
private:
	Actor* m_owner;
	bool m_started;
	bool m_enabled;

	void OnEnable();
	void OnDisable();
};
