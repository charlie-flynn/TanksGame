#include "Actor.h"
#include "Transform2D.h"

Actor::Actor() 
	: m_transform(new Transform2D(*this)), m_enabled(false), m_started(false)
{

}

Actor::~Actor()
{
	
}

Actor Actor::Instantiate(Actor& actor, Transform2D* parent, const Vec2 position, const float rotation)
{
	actor.m_transform->SetLocalPosition(position);
	actor.m_transform->SetLocalRotation(Mat3::createRotation(rotation));
	if (parent != nullptr)
		parent->AddChild(actor.m_transform);

	// add actor to current scene

	// return actor
	return actor;
}

void Actor::Destroy(Actor* actor)
{

	// remove children

	// unchild from parent

	// remove from current scene
}

void Actor::OnEnable()
{
}

void Actor::OnDisable()
{
}

Transform2D Actor::GetTransformDereferenced()
{
	return *m_transform;
}

void Actor::Start()
{
	m_started = true;
}

void Actor::Update()
{
}

void Actor::End()
{
}

void Actor::OnCollision(Actor* other)
{
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
