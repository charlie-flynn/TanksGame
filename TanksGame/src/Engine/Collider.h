#pragma once
#include "Component.h"

class CircleCollider;

class Collider : public Component
{
public:
	Actor* GetCollidedActor() { return m_collidedActor; };
	bool CheckCollision(Actor* other);
	virtual void Draw() {};
	virtual bool CheckCollisionCircle(CircleCollider* other) { return false; };
protected:
	Actor* m_collidedActor;
};