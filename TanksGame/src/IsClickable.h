#pragma once
#include "../engine/Component.h"


class IsClickable : public Component 
{
public:
	void SetOnClickEvent(void (*functionPointer)()) { OnClickEvent = functionPointer; };
	void Update(double deltaTime) override;

private:
	// this is a function pouinter !  pointer but it points to a function
	void (*OnClickEvent)() {};
};