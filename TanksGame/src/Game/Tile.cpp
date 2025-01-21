#include "Tile.h"
#include "Engine/Transform2D.h"
#include "raylib.h"

Tile::Tile() : Actor("Tile")
{
	AddComponent<SquareCollider>(m_collider = new SquareCollider(new Vec2(51, 51), this));
	m_health = 3;
}

void Tile::Update(double deltaTime)
{
	// draw tile
	DrawRectangleV({ GetTransform()->GetGlobalPosition().x, GetTransform()->GetGlobalPosition().y }, { 50, 50 }, BROWN);
	DrawRectangleLines(GetTransform()->GetGlobalPosition().x, GetTransform()->GetGlobalPosition().y, 50, 50, DARKBROWN);
}

void Tile::OnCollision()
{
	if (GetCollider()->GetCollidedActor()->GetName() == "Bullet")
	{
		m_health--;
		if (m_health <= 0)
			Destroy(this);
	}
}
