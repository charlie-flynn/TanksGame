#pragma once
#include "../engine/Actor.h"
class Button : public Actor
{
private:
	char* text;
	int textLength;
public:
	Button(Vec2 scale, char* text, int textLength, void (*clickEvent)() = nullptr);
	~Button();

	void Update(double deltaTime) override;
};