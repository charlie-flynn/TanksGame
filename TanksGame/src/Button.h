#pragma once
#include "../engine/Actor.h"


class Button : public Actor
{
public:
	Button(void (*clickEvent)() = nullptr);
	~Button();

	void Start() override;
	void Update(double deltaTime) override;
};