#pragma once

#include "Engine/Actor.h"

class SquareCollider;

class TankBottom : public Actor
{
public:
	TankBottom();
	void Update(double deltaTime) override;
	float GetSpeed() { return m_speed; };
	Collider* GetCollider() override { return (Collider*)m_collider; };

private:
	float m_speed;
	SquareCollider* m_collider;

};
