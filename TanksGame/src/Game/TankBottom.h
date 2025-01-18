#pragma once

#include "Engine/Actor.h"

class CircleCollider;

class TankBottom : public Actor
{
public:
	TankBottom();
	void Update(double deltaTime) override;
	float GetSpeed() { return m_speed; };

private:
	float m_speed;
	CircleCollider* m_collider;

};
