#include "raylib.h"
#include "engine/Transform2D.h"
#include "engine/TestActor.h"
#include "engine/TwostActor.h"

int main(void)
{
    InitWindow(800, 450, "raylib [core] example - basic window");
    // test
    TestActor testGuy = TestActor();
    TwostActor testBlue = TwostActor();
    TwostActor testTwue = TwostActor();

    Actor::Instantiate(testGuy, nullptr, MathLibrary::Vector2(39, 39), 0);
    Actor::Instantiate(testBlue, testGuy.GetTransform(), MathLibrary::Vector2(49, 49), 0);
    Actor::Instantiate(testTwue, testGuy.GetTransform(), MathLibrary::Vector2(100, 100), 0);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
        testGuy.Update();
        testBlue.Update();
        testTwue.Update();
    }
    
    CloseWindow();

    return 0;
}