#include "Gem.h"
#include "Engine/Actor.h"
#include "Engine/Transform2D.h"
#include "raylib.h"

Gem::Gem()
{
}

void Gem::Update(double deltaTime)
{
	DrawPoly({ GetTransform()->GetGlobalPosition().x, GetTransform()->GetGlobalPosition().y }, 4, 15, 45, SKYBLUE);
}

void Gem::OnCollision(Actor* collidedActor)
{
	if (collidedActor->GetName() == "Tank")
	{
		Destroy(this);
	}
}
