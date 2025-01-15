#pragma once
#include "../engine/Actor.h"
class Button : public Actor
{
public:
	Button(Vec2 scale, void (*clickEvent)() = nullptr);
	~Button() = default;

	void Start() override;
	void Update(double deltaTime) override;
};