#include "Engine/Scene.h"
#include "LandscapeScene.h"
#include "TankBottom.h"
#include "Engine/Transform2D.h"
#include "Gem.h"

#include <iostream>

LandscapeScene::LandscapeScene()
{
	static const int ROWS = 20;
	static const int COLS = 20;

	int m_tiles[ROWS * COLS];

	int m_tileWdith = 80;
	int m_tileHeight = 50;
}

LandscapeScene::~LandscapeScene()
{

}

void LandscapeScene::LoadRandomizer()
{
}

Color LandscapeScene::GetTileColor(int tileValue)
{
	return Color();
}

void LandscapeScene::Start()
{
	Actor::Instantiate(new TankBottom(), nullptr, Vec2(30, 30), 0);

	Actor::Instantiate(new Gem(), nullptr, Vec2(200, 200), 0);

	std::cout << "ACK" << std::endl;
}

void LandscapeScene::Update(double deltatime)
{
	Scene::Update(deltatime);

}

void LandscapeScene::End()
{
}

//LandscapeScene::LoadRandomizer(unsigned int seed)
//{
//  Raylib.SetRandomSeed((unsigned int) time(NULL));
//
//}
//
//int* LoadRandomSequence(unsigned int count, int min, int max);
//void UnloadRandomSequence(int* sequence);