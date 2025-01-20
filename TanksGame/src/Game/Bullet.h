#pragma once
#include "Engine/Actor.h"

class Bullet : public Actor
{
public:
	Bullet(Vec2 direction = Vec2(0, 1));
	void Update(double deltaTime) override;
private:
	Vec2 m_direction;
};