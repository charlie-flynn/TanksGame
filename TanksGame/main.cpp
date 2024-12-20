#include "raylib.h"
#include "engine/Transform2D.h"
#include "engine/TestActor.h"
#include "engine/TwostActor.h"
#include "src/TankBottom.h"

int main(void)
{
    InitWindow(800, 450, "raylib [core] example - basic window");

    TankBottom tankBottom = TankBottom();
    TwostActor testBlue = TwostActor();
    TwostActor testTwue = TwostActor();

    Actor::Instantiate(&tankBottom, nullptr, MathLibrary::Vector2(39, 39), 0);
    Actor::Instantiate(&testBlue, tankBottom.GetTransform(), MathLibrary::Vector2(49, 49), 0);
    Actor::Instantiate(&testTwue, tankBottom.GetTransform(), MathLibrary::Vector2(100, 100), 0);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
        tankBottom.Update(0.0024);
        testBlue.Update(1);
        testTwue.Update(1);
    }
    
    CloseWindow();

    return 0;
}