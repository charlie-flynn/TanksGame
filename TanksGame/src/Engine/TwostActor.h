#pragma once
#include "Engine/Actor.h"

class TwostActor : public Actor
{
public: 
	TwostActor() = default;
	void Update(double deltaTime) override;
};