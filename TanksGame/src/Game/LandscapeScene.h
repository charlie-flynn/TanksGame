#pragma once
#include "Engine/Scene.h"
#include "raylib.h"

class LandscapeScene : public Scene
{
public:
	LandscapeScene();
	~LandscapeScene();

private:
	void LoadRandomizer();
	Color GetTileColor(int tileValue);
	virtual void Start();
	virtual void Update(float deltatime);
	virtual void End();



};
