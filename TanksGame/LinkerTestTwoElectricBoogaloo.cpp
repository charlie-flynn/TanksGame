#include "raylib.h"


Color color = { 100, 100, 100, 255 };


int main() 
{
	InitWindow(255, 255, "cool");

	while (!WindowShouldClose) 
	{
		BeginDrawing();

		ClearBackground(RAYWHITE);

		DrawText("YIPEE", 133, 133, 20, BLACK);

		EndDrawing();
	}
}