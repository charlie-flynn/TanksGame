#pragma once
#include "Engine/Scene.h"

class WinScene : public Scene
{
public:
	void Start() override;
	void Update(double deltaTime) override;
	void End() override;
private:
	static void PlayAgain();
	static void RickRoll();
};