#pragma once
#include "Engine/Actor.h"
#include "Engine/SquareCollider.h"

class Bullet : public Actor
{
public:
	Bullet();
	void Update(double deltaTime) override;
	SquareCollider* GetCollider() { return m_collider; };

private:
	Vec2 m_direction;
	SquareCollider* m_collider;
};