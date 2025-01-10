#include "raylib.h"
#include "Engine/Transform2D.h"
#include "Game/TestActor.h"
#include "Game/TwostActor.h"

int main(void)
{
    InitWindow(800, 450, "raylib [core] example - basic window");

    TestActor testGuy = TestActor();
    TwostActor testBlue = TwostActor();

    Actor::Instantiate(testGuy, nullptr, MathLibrary::Vector2(39, 39), 0);
    Actor::Instantiate(testBlue, nullptr, MathLibrary::Vector2(49, 49), 0);

    testGuy.GetTransform()->AddChild(testBlue.GetTransform());

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
        testGuy.Update();
        testBlue.Update();
    }
    
    CloseWindow();

    return 0;
}