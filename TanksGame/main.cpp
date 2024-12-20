#include "raylib.h"
#include "engine/Transform2D.h"
#include "engine/TestActor.h"
#include "engine/TwostActor.h"
#include "src/TankBottom.h"
#include "src/TankTreads.h"

int main(void)
{
    InitWindow(800, 450, "raylib [core] example - basic window");

    TankBottom tankBottom = TankBottom();
    TankTreads tankTreads = TankTreads();

    Actor::Instantiate(&tankBottom, nullptr, MathLibrary::Vector2(39, 39), 0);
    Actor::Instantiate(&tankTreads, tankBottom.GetTransform(), MathLibrary::Vector2(25, 25), 0);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        tankTreads.Update(0.0024);
        tankBottom.Update(0.0024);

        EndDrawing();
    }
    
    CloseWindow();

    return 0;
}