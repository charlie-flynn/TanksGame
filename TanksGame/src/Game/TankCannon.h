#pragma once
#include "Engine/Actor.h"

class TankCannon : public Actor
{
public:
	void Update(double deltaTime) override;
private:
	double m_fireRate;
};