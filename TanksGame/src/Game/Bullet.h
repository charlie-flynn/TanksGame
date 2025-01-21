#pragma once
#include "Engine/Actor.h"
#include "Engine/SquareCollider.h"

class Bullet : public Actor
{
public:
	Bullet(Vec2 direction = Vec2(0, 1));
	void Update(double deltaTime) override;
	SquareCollider* GetCollider() { return m_collider; };

private:
	Vec2 m_direction;
	SquareCollider* m_collider;
};