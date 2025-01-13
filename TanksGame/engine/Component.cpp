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
	delete m_owner;
	m_owner = nullptr;
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
