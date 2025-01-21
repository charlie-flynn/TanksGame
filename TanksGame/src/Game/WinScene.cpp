#include "WinScene.h"
#include "Button.h"
#include "raylib.h"
#include "Engine/Game.h"
#include "LandscapeScene.h"

void WinScene::Start()
{
	Actor::Instantiate(new Button(Vec2(GetScreenWidth() / 2, 120), (char*)"Play Again?", 11, PlayAgain), nullptr, Vec2(GetScreenWidth() / 4.0f, GetScreenHeight() / 1.6f), 0);
	Actor::Instantiate(new Button(Vec2(GetScreenWidth() / 2, 120), (char*)"Check Our Twitter!", 18, RickRoll), nullptr, Vec2(GetScreenWidth() / 4.0f, GetScreenHeight() / 1.2f), 0);
}

void WinScene::Update(double deltaTime)
{
	DrawText("You Won!!!", GetScreenWidth() / 6, 40, 120, GOLD);

	Scene::Update(deltaTime);
}

void WinScene::End()
{
}

void WinScene::PlayAgain()
{
	Game::SetCurrentScene(new LandscapeScene());
}

void WinScene::RickRoll()
{
	OpenURL("https://youtu.be/dQw4w9WgXcQ");
}
