#pragma once
#include "Engine/Actor.h"

class Gem : public Actor
{
public:
	Gem();
	void Update(double deltaTime) override;
	void OnCollision(Actor* collidedActor) override;
};