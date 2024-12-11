#include "Actor.h"
#include "Transform2D.h"

Actor::Actor()
{
}

Actor::~Actor()
{
}

Actor Actor::Instantiate(Actor* actor, Transform2D* parent, Vec2 position, float rotation)
{
	actor->m_transform->SetLocalPosition(position);
	actor->m_transform->SetLocalRotation(Mat3::createRotation(rotation));
	if (parent != nullptr)
		parent->AddChild(actor->m_transform);

	// add actor to current scene

	// return actor
	return *actor;
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
