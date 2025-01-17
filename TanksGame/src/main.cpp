#include "raylib.h"
#include "Engine/Transform2D.h"
#include "Game/TankBottom.h"
#include "Game/Game.h"
#include "Game/TankTreads.h"
#include "Game/Button.h"
#include "Engine/Actor.h"
#include <iostream>

void TestFunction()
{
    std::cout << "Test!" << std::endl;
}

int main(void)
{

    Game game = Game();
    game.Run();

    return 0;


}