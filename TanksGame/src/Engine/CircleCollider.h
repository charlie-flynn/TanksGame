#pragma once
#include "Collider.h"
#include "Component.h"

class CircleCollider : public Collider
{
public:
	CircleCollider(Actor* owner = nullptr, float radius = 1.0f);
	void Draw() override;
	float GetCollisionRadius() { return m_collisionRadius; };
	void SetCollisionRadius(float value) { m_collisionRadius = value; };
	bool CheckCollisionCircle(CircleCollider* other) override;
private:
	float m_collisionRadius;
};