#pragma once
#include "Engine/Scene.h"
#include "raylib.h"

class LandscapeScene : public Scene
{
public:
	LandscapeScene();
	~LandscapeScene();
	 void Start() override;
	void Update(double deltatime) override;
	void End() override;

private:
	void LoadRandomizer();
	Color GetTileColor(int tileValue);



};
