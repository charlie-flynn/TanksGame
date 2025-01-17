#pragma once
#include "Engine/Scene.h"
#include "raylib.h"

class LandscapeScene
{
public:
	LandscapeScene();
	~LandscapeScene();

private:
	void LoadRandomizer();
	void Update(float deltatime);

};
