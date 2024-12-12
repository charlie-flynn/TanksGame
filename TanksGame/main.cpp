#include "raylib.h"
#include "Transform2D.h"
#include "TestActor.h"

int main(void)
{
    InitWindow(800, 450, "raylib [core] example - basic window");

    TestActor testGuy = TestActor(*Transform2D(testGuy));

    Actor::Instantiate(testGuy, testGuy, MathLibrary::Vector2(39, 39), 0);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
        testGuy.Update();
    }
    
    CloseWindow();

    return 0;
}