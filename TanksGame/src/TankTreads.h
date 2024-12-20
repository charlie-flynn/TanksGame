#pragma once
#include "../engine/Actor.h"

class TankTreads : public Actor
{
public:
	void Update(double deltaTime) override;
	void RotateToDirection(Vec2 direction);
};