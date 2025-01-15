#include "Button.h"
#include "IsClickable.h"
#include "../engine/Transform2D.h"
#include <raylib.h>

Button::Button(Vec2 scale, char* text, int textLength, void(*clickEvent)()) : Actor()
{
	AddComponent<IsClickable>()->SetOnClickEvent(clickEvent);
	GetTransform()->SetLocalScale(scale);
	this->text = text;
	this->textLength = textLength;
}

Button::~Button()
{
	delete text;
}

void Button::Update(double deltaTime)
{
	Actor::Update(deltaTime);

	Vec2 mousePosition = Vec2(GetMousePosition().x, GetMousePosition().y);
	Vec2 buttonPosition = GetTransform()->GetGlobalPosition();
	Vec2 buttonScale = GetTransform()->GetGlobalScale();

	DrawRectangle(
		buttonPosition.x,
		buttonPosition.y,
		1 * buttonScale.x,
		1 * buttonScale.y,
		RED);

	if (text != nullptr)
		DrawTextPro(Font(), text, { (buttonScale.x / 2) - textLength * 2.52f, buttonScale.y / 3}, {-buttonPosition.x, -buttonPosition.y}, 0, buttonScale.y / 3, 1, {0, 0, 0, 255});

	if (mousePosition.x < buttonPosition.x + buttonScale.x &&
		mousePosition.x + 2 > buttonPosition.x &&
		mousePosition.y < buttonPosition.y + buttonScale.y &&
		mousePosition.y + 2 > buttonPosition.y)
	{
		DrawRectangle(
			buttonPosition.x,
			buttonPosition.y,
			1 * buttonScale.x,
			1 * buttonScale.y,
			Color{0, 0, 0, 50});
	}
}
