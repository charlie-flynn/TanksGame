#include "Game.h"
#include "Engine/Scene.h"
#include "Game/LandscapeScene.h"

#include <chrono>
#include <iostream>
#include <raylib.h>

Scene* Game::m_currentScene = nullptr;
Game::Game()
{
    m_scenes = DynamicArray<Scene*>();
    m_currentScene = new LandscapeScene();
}

Scene* Game::GetScene(int index)
{
    return m_scenes[index];
}

void Game::RemoveScene(Scene* scene)
{
    m_scenes.Remove(scene);
}

void Game::AddScene(Scene* scene)
{
    m_scenes.AddUnique(scene);
}

void Game::SetCurrentScene(Scene* scene)
{
    if (m_currentScene != nullptr)
        m_currentScene->End();
    m_currentScene = scene;
    m_currentScene->Start();
}

void Game::Run()
{
    InitWindow(800, 800, "Tank Game");
    SetTargetFPS(60);
    double deltaTime = 1;
    SetCurrentScene(new LandscapeScene());

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        m_currentScene->Update(deltaTime);

        EndDrawing();

        deltaTime = GetFrameTime();
    }

    m_currentScene->End();

    CloseWindow();
}
// DEPRECATED CODE - dont need it anymore
/*
void Game::Start()
{
    InitWindow(GetMonitorWidth(0), GetMonitorHeight(0), "raylib [core] example - basic window");
    ToggleFullscreen();
    SetExitKey(KEY_ESCAPE);
}

void Game::Update()
{
    TankCannon tankCannon = TankCannon();
    TankBottom tankBottom = TankBottom();
    TankTreads tankTreads = TankTreads();
    Button testButton = Button(Vec2(120, 30), (char*)"Test Button", 11, *TestFunction);
    TestActor testCollisionActor = TestActor();
    Gem testGem = Gem();

    Actor::Instantiate(&tankBottom, nullptr, Vec2(39, 39), 0);
    Actor::Instantiate(&tankTreads, tankBottom.GetTransform(), Vec2(25, 25), 0);
    Actor::Instantiate(&tankCannon, tankBottom.GetTransform(), Vec2(25, 25), 0);
    Actor::Instantiate(&testButton, nullptr, Vec2(50, 50), 0);
    Actor::Instantiate(&testCollisionActor, nullptr, Vec2(120, 200), 0);
    Actor::Instantiate(&testGem, nullptr, Vec2(300, 300), 0);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        tankTreads.Update(0.0024);
        tankBottom.Update(0.0024);
        tankCannon.Update(0.0024);
        testButton.Update(0.0024);
        testCollisionActor.Update(0.024);
        testGem.Update(0.024);

        if (testCollisionActor.GetCollider()->CheckCollisionSquare((SquareCollider*)tankBottom.GetCollider()))
            std::cout << "COLISION" << std::endl;

        if (testGem.GetCollider()->CheckCollisionSquare((SquareCollider*)tankBottom.GetCollider()))
            testGem.OnCollision(testGem.GetCollider()->GetCollidedActor());

        EndDrawing();
    }

    CloseWindow();
}

void Game::End()
{
}

void Game::TestFunction()
{
    std::cout << "Button Clicked!" << std::endl;
}
*/
