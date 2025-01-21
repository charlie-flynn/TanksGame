#include "Gem.h"
#include "Engine/Actor.h"
#include "Engine/Transform2D.h"
#include "raylib.h"

Gem::Gem() : Actor("Gem")
{
	AddComponent<SquareCollider>(m_collider = new SquareCollider(new Vec2(15, 15), this));
}

Gem::~Gem()
{
	Actor::~Actor();
	delete m_collider;
}

void Gem::Update(double deltaTime)
{
	DrawPoly({ GetTransform()->GetGlobalPosition().x, GetTransform()->GetGlobalPosition().y }, 4, 15, 0, SKYBLUE);
}

void Gem::OnCollision()
{
	if (GetCollider()->GetCollidedActor()->GetName() == "Tank")
	{
		Destroy(this);
	}
}
