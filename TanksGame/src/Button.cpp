#include "Button.h"
#include "IsClickable.h"
#include "../engine/Transform2D.h"
#include <raylib.h>

Button::Button(void(*clickEvent)()) : Actor()
{
	AddComponent<IsClickable>()->SetOnClickEvent(clickEvent);
	GetTransform()->SetLocalScale(Vec2(40, 40));
}

Button::~Button() 
{

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
		GetTransform()->GetGlobalScale().x,
		GetTransform()->GetGlobalScale().y,
		RED);
}
