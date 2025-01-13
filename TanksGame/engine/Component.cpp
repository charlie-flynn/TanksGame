#include "Component.h"

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
