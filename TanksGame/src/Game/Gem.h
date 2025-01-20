#pragma once
#include "Engine/Actor.h"
#include "Engine/SquareCollider.h"

class Gem : public Actor
{
public:
	Gem();
	void Update(double deltaTime) override;
	void OnCollision(Actor* collidedActor) override;
	SquareCollider* GetCollider() { return m_collider; }
private:
	SquareCollider* m_collider;
};