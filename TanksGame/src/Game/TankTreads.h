#pragma once
#include "Engine/Actor.h"

class TankTreads : public Actor
{
public:
	void Update(double deltaTime) override;
	void RotateToDirection(Vec2 direction);
};