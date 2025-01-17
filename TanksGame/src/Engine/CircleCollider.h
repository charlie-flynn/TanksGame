#pragma once
#include "Collider.h"

class CircleCollider : public Collider
{
public:
	void Draw() override;
	float GetCollisionRadius() { return m_collisionRadius; };
	void SetCollisionRadius(float value) { m_collisionRadius = value; };
	bool CheckCollisionCircle(CircleCollider* other) override;
private:
	float m_collisionRadius;
};