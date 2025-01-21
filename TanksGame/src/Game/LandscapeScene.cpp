#include "Engine/Scene.h"
#include "LandscapeScene.h"

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

//LandscapeScene::LoadRandomizer(unsigned int seed)
//{
//  Raylib.SetRandomSeed((unsigned int) time(NULL));
//
//}
//
//int* LoadRandomSequence(unsigned int count, int min, int max);
//void UnloadRandomSequence(int* sequence);