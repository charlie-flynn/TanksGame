#include "Actor.h"
#include "Transform2D.h"

Actor::Actor() 
	: m_transform(new Transform2D(*this)), m_enabled(false), m_started(false)
{
	Start();
}

Actor::~Actor()
{
	delete m_transform;
}

Actor* Actor::Instantiate(Actor* actor, Transform2D* parent, const Vec2 position, const float rotation)
{
	// set the actor's position, rotation, and parent
	actor->m_transform->SetLocalPosition(position);
	actor->m_transform->SetLocalRotation(Mat3::createRotation(rotation));
	if (parent != nullptr)
		parent->AddChild(actor->m_transform);

	// add actor to current scene
	
	// return actor
	return actor;
}

void Actor::Destroy(Actor* actor)
{

	// remove children
	for (int i = 0; i < m_transform->GetChildren().Length(); i++)
	{
		m_transform->RemoveChild(m_transform->GetChildren()[i]);
	}

	// unchild from parent
	m_transform->GetParent()->RemoveChild(this->GetTransform());

	// remove from current scene
}

void Actor::Start()
{
	m_started = true;
}

void Actor::SetEnabled(const bool value)
{
	// if enabled is already equal to the value, dont do anything
	if (m_enabled = value)
		return;

	// set enabled equal to the value, then call the OnEnable or OnDisable based on the value
	m_enabled = value;

	if (value)
		OnEnable();
	else
		OnDisable();
}

Transform2D* Actor::GetTransform()
{
	return m_transform;
}
