#pragma once
#include "../engine/Component.h"


class IsClickable : public Component 
{
public:
	IsClickable();
	IsClickable(Actor* owner);
	~IsClickable();
	void SetOnClickEvent(void (*functionPointer)()) { OnClickEvent = functionPointer; };
	void Update(double deltaTime) override;

private:
	// this is a function pointer !  pointer but it points to a function
	void (*OnClickEvent)() {};
};