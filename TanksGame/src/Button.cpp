#include "Button.h"
#include "IsClickable.h"
#include "../engine/Transform2D.h"
#include <raylib.h>

Button::Button(Vec2 scale, void(*clickEvent)()) : Actor()
{
	AddComponent<IsClickable>()->SetOnClickEvent(clickEvent);
	GetTransform()->SetLocalScale(scale);
}

void Button::Start()
{

}

void Button::Update(double deltaTime)
{
	Actor::Update(deltaTime);



	DrawRectangle(
		GetTransform()->GetGlobalPosition().x,
		GetTransform()->GetGlobalPosition().y,
		1 * GetTransform()->GetGlobalScale().x,
		1 * GetTransform()->GetGlobalScale().y,
		RED);

	Vec2 mousePosition = Vec2(GetMousePosition().x, GetMousePosition().y);
	Vec2 buttonPosition = GetTransform()->GetGlobalPosition();
	Vec2 buttonScale = GetTransform()->GetGlobalScale();

	if (mousePosition.x < buttonPosition.x + buttonScale.x &&
		mousePosition.x + 2 > buttonPosition.x &&
		mousePosition.y < buttonPosition.y + buttonScale.y &&
		mousePosition.y + 2 > buttonPosition.y)
	{
		DrawRectangle(
			GetTransform()->GetGlobalPosition().x,
			GetTransform()->GetGlobalPosition().y,
			1 * GetTransform()->GetGlobalScale().x,
			1 * GetTransform()->GetGlobalScale().y,
			Color{0, 0, 0, 50});
	}
}
