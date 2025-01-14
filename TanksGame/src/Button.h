#pragma once
#include "../engine/Actor.h"


class Button : public Actor
{
public:
	Button(void (*clickEvent)());
	~Button();

	void Update(double deltaTime) override;
};