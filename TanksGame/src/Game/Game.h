#pragma once
#include "Engine/DynamicArray.h"

class Scene;

class Game
{
public:
	Game();

	Scene* GetScene(int index);
	void RemoveScene(Scene* scene);
	void AddScene(Scene* scene);
	Scene* GetCurrentScene() { return m_currentScene; };
	void SetCurrentScene(Scene* scene);
	void Run();
private:
	DynamicArray<Scene*> m_scenes;
	Scene* m_currentScene;

	// DEPRECATED CODE
	/*
	void Start();
	void Update();
	void End();
	static void TestFunction();
	*/
};