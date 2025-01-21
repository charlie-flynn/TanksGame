#include "Engine/Scene.h"
#include "LandscapeScene.h"
#include "TankBottom.h"
#include "Engine/Transform2D.h"
#include "Gem.h"
#include "Tile.h"

#include <iostream>

LandscapeScene::LandscapeScene()
{

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

	const int rows = 16;
	const int columns = 16;

	{
		Vec2 gemPosition1 = Vec2();
		Vec2 gemPosition2 = Vec2();
		Vec2 gemPosition3 = Vec2();

		do
		{
			do
			{
				gemPosition1 = Vec2(GetRandomValue(0, 16), GetRandomValue(0, 16));
			} while (gemPosition1.x <= 1 || gemPosition1.y <= 1);

			do
			{
				gemPosition2 = Vec2(GetRandomValue(0, 16), GetRandomValue(0, 16));
			} while (gemPosition2.x <= 1 || gemPosition2.y <= 1);

			do
			{
				gemPosition3 = Vec2(GetRandomValue(0, 16), GetRandomValue(0, 16));
			} while (gemPosition3.x <= 1 || gemPosition3.y <= 1);
		} while (gemPosition1 == gemPosition2 || gemPosition2 == gemPosition3 || gemPosition3 == gemPosition1);

		std::cout << gemPosition1.x << ", " << gemPosition1.y << std::endl;
		std::cout << gemPosition2.x << ", " << gemPosition2.y << std::endl;
		std::cout << gemPosition3.x << ", " << gemPosition3.y << std::endl;

		Actor::Instantiate(new Gem(), nullptr, gemPosition1 * 50, 0);
		Actor::Instantiate(new Gem(), nullptr, gemPosition2 * 50, 0);
		Actor::Instantiate(new Gem(), nullptr, gemPosition3 * 50, 0);
	}


	for (int x = 0; x < rows; x++)
	{
		for (int y = 0; y < columns; y++)
		{
			Vec2 position = Vec2(50 * x, 50 * y);

			if (x != 0 && x != 1  || y != 0 && y != 1)
				Actor::Instantiate(new Tile(), nullptr, position, 0);
		}
	}


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