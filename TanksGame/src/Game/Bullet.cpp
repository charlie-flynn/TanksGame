#include "Bullet.h"
#include "Engine/Actor.h"
#include "Engine/Transform2D.h"
#include "Engine/SquareCollider.h"
#include "raylib.h"

Bullet::Bullet() : Actor("Bullet")
{
	AddComponent<SquareCollider>(m_collider = new SquareCollider(new Vec2(10, 10), this));
}

void Bullet::Update(double deltaTime)
{
	// move
	GetTransform()->Translate(GetTransform()->GetForwardVector() * 100 * deltaTime);

	// draw
	Rectangle rectangle = Rectangle();
	rectangle.x = GetTransform()->GetGlobalPosition().x;
	rectangle.y = GetTransform()->GetGlobalPosition().y;
	rectangle.width = 10 * GetTransform()->GetGlobalScale().x;
	rectangle.height = 10 * GetTransform()->GetGlobalScale().y;

	DrawRectanglePro(rectangle, { 0, 0 }, -GetTransform()->GetGlobalRotationAngle() * (180 / PI), RED);
}

void Bullet::OnCollision()
{
	if (GetCollider()->GetCollidedActor()->GetName() == "Tile")
		Destroy(this);
}
