#pragma once
#include "Engine/Component.h"


class IsClickable : public Component 
{
public:
	IsClickable() : Component() {};
	IsClickable(Actor* owner) : Component(owner) {};
	~IsClickable() = default;
	void SetOnClickEvent(void (*functionPointer)()) { OnClickEvent = functionPointer; };
	void Update(double deltaTime) override;

private:
	// this is a function pointer !  pointer but it points to a function
	void (*OnClickEvent)() {};
};