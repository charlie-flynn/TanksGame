#pragma once
#include "Engine/Actor.h"
#include "Engine/SquareCollider.h"

class Gem : public Actor
{
public:
	Gem();
	~Gem();
	void Update(double deltaTime) override;
	void OnCollision() override;
	Collider* GetCollider() override { return (Collider*)m_collider; }
private:
	SquareCollider* m_collider;
};