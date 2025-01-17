#include "Game.h"
#include "Engine/Actor.h"
#include "Game/TankBottom.h"
#include "Game/TankTreads.h"
#include "Game/Button.h"

#include <iostream>
#include <raylib.h>

void Game::Run()
{
	Start();
    Update();
	End();
}

void Game::Start()
{
    InitWindow(800, 450, "raylib [core] example - basic window");
}

void Game::Update()
{
    TankBottom tankBottom = TankBottom();
    TankTreads tankTreads = TankTreads();
    Button testButton = Button(Vec2(120, 30), (char*)"Test Button", 11, *TestFunction);

    Actor::Instantiate(&tankBottom, nullptr, Vec2(39, 39), 0);
    Actor::Instantiate(&tankTreads, tankBottom.GetTransform(), Vec2(25, 25), 0);
    Actor::Instantiate(&testButton, nullptr, Vec2(50, 50), 0);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        tankTreads.Update(0.0024);
        tankBottom.Update(0.0024);
        testButton.Update(0.0024);

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
