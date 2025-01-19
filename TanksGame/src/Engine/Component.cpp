#include "Component.h"
#include "Actor.h"


Component::Component(Actor* owner)
{
	m_owner = owner;
	m_enabled = true;
	m_started = false;
}

Component::~Component()
{
	if (m_owner != nullptr)
		delete m_owner;
	m_owner = nullptr;
}

Component::Component(Component& other)
{
	m_owner = other.m_owner;
	m_started = other.m_started;
	m_enabled = other.m_enabled;
}

void Component::SetEnabled(bool value)
{
	if (m_enabled = value)
		return;

	m_enabled = value;
	if (m_enabled)
		OnEnable();
	else
		OnDisable();
}

void Component::OnEnable()
{
}

void Component::OnDisable()
{
}
