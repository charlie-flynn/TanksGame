#include "Actor.h"
#include "Transform2D.h"
#include "Component.h"
#include "Game.h"
#include "Scene.h"

Actor::Actor(char const* name)
	: m_transform(new Transform2D(*this)), m_enabled(false), m_started(false), m_name(name)
{
}

Actor::~Actor()
{
	delete m_transform;
	m_transform = nullptr;
	delete m_name;
	m_name = nullptr;
}

Actor* Actor::Instantiate(Actor* actor, Transform2D* parent, const Vec2 position, const float rotation)
{
	// set the actor's position, rotation, and parent
	actor->m_transform->SetLocalPosition(position);
	actor->m_transform->SetLocalRotation(Mat3::createRotation(rotation));
	if (parent != nullptr)
		parent->AddChild(actor->m_transform);

	// add actor to current scene
	Game::GetCurrentScene()->AddActor(actor);

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
	if (m_transform->GetParent() != nullptr)
		m_transform->GetParent()->RemoveChild(this->GetTransform());

	// remove from current scene
	Game::GetCurrentScene()->RemoveActor(this);
}

void Actor::Start()
{
	m_started = true;
}

void Actor::Update(double deltaTime)
{
	for (int i = 0; i < m_components.Length(); i++)
	{
		m_components[i]->Update(deltaTime);
	}
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
