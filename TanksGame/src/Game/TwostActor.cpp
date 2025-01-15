#include "TwostActor.h"
#include "raylib.h"
#include "Engine/Transform2D.h"

void TwostActor::Update(double deltaTime)
{
	// draw the actor
	DrawRectangleV(Vector2() = { GetTransform()->GetGlobalPosition().x, GetTransform()->GetGlobalPosition().y },
		Vector2() = { GetTransform()->GetGlobalScale().x * 50, GetTransform()->GetGlobalScale().y * 50 }, BLUE);
}