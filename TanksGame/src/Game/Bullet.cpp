#include "Bullet.h"
#include "Engine/Actor.h"
#include "Engine/Transform2D.h"

Bullet::Bullet(Vec2 direction)
{
	m_direction = direction.getNormalized();
}

void Bullet::Update(double deltaTime)
{
	GetTransform()->Translate(m_direction * 20 * deltaTime);
}
