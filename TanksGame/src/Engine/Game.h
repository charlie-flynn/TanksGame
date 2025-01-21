#pragma once
#include "Engine/DynamicArray.h"
#include "Scene.h"

class Game
{
public:
	Game();

	Scene* GetScene(int index);
	void RemoveScene(Scene* scene);
	void AddScene(Scene* scene);
	static Scene* GetCurrentScene() { return m_currentScene; };
	static void SetCurrentScene(Scene* scene);
	void Run();
private:
	DynamicArray<Scene*> m_scenes;
	static Scene* m_currentScene;

	// DEPRECATED CODE
	/*
	void Start();
	void Update();
	void End();
	static void TestFunction();
	*/
};

