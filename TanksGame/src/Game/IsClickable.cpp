#include "IsClickable.h"
#include "raylib.h"
#include "Engine/Actor.h"
#include "Engine/Transform2D.h"

void IsClickable::Update(double deltaTime)
{
	Vec2 mousePosition = Vec2(GetMousePosition().x, GetMousePosition().y);
	Vec2 buttonPosition = GetOwner()->GetTransform()->GetGlobalPosition();
	Vec2 buttonScale = GetOwner()->GetTransform()->GetGlobalScale();

	// checks if the mouse is hovering over the button this component is attached to
	// if it is, call OnClickEvent if the player clicks
	if (mousePosition.x < buttonPosition.x + buttonScale.x &&
		mousePosition.x + 2 > buttonPosition.x &&
		mousePosition.y < buttonPosition.y + buttonScale.y &&
		mousePosition.y + 2 > buttonPosition.y)
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			OnClickEvent();
}
