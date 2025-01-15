#include "raylib.h"
#include "engine/Transform2D.h"
#include "engine/TestActor.h"
#include "engine/TwostActor.h"
#include "src/TankBottom.h"
#include "src/TankTreads.h"
#include "src/Button.h"
#include <iostream>

void TestFunction()
{
    std::cout << "Test!" << std::endl;
}

int main(void)
{
    InitWindow(800, 450, "raylib [core] example - basic window");
    
    TankBottom tankBottom = TankBottom();
    TankTreads tankTreads = TankTreads();
    Button testButton = Button(Vec2(120, 30), *TestFunction);

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

    return 0;


}