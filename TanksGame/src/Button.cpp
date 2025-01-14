#include "Button.h"
#include "IsClickable.h"
#include "../engine/Transform2D.h"
#include <raylib.h>

Button::Button(void (*clickEvent)())
{
	Actor::Actor();
	AddComponent<IsClickable>()->SetOnClickEvent(clickEvent);
}

Button::~Button()
{
	Actor::~Actor();
}

void Button::Update(double deltaTime)
{
	Actor::Update(deltaTime);

	DrawRectangle(
		GetTransform()->GetGlobalPosition().x,
		GetTransform()->GetGlobalPosition().y,
		GetTransform()->GetGlobalScale().x,
		GetTransform()->GetGlobalScale().y,
		RED);
}
