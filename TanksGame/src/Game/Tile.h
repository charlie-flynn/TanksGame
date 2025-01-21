#pragma once
#include "Engine/Actor.h"
#include "Engine/SquareCollider.h"


class Tile : public Actor
{
public:
	Tile();
	void Update(double deltaTime) override;
	void OnCollision() override;
	Collider* GetCollider() override { return (Collider*)m_collider; };
private:
	int m_health;
	SquareCollider* m_collider;
};
