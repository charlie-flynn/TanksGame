#pragma once

#include "../engine/Actor.h"

class TankBottom : public Actor
{
public:
	TankBottom();
	void Update(double deltaTime) override;
	float GetSpeed() { return m_speed; };

private:
	float m_speed;

};
