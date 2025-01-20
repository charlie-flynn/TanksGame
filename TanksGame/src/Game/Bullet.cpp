#include "Bullet.h"
#include "Engine/Actor.h"
#include "Engine/Transform2D.h"
#include "Engine/SquareCollider.h"
#include "raylib.h"

Bullet::Bullet(Vec2 direction)
{
	m_direction = direction.getNormalized();
	AddComponent<SquareCollider>(m_collider = new SquareCollider(new Vec2(10, 10), this));
}

void Bullet::Update(double deltaTime)
{
	// move
	GetTransform()->Translate(m_direction * 20 * deltaTime);

	// draw
	Rectangle rectangle = Rectangle();
	rectangle.x = 10 * GetTransform()->GetGlobalPosition().x;
	rectangle.y = 10 * GetTransform()->GetGlobalPosition().y;
	rectangle.width = GetTransform()->GetGlobalScale().x;
	rectangle.height = GetTransform()->GetGlobalScale().y;

	DrawRectanglePro(rectangle, { 0, 0 }, GetTransform()->GetGlobalRotationAngle() * (180 / PI), RED);
}
