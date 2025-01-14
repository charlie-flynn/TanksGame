#include "IsClickable.h"
#include "raylib.h"

void IsClickable::Update(double deltaTime) 
{
	// todo: check if the mouse is hovering over the owner and left mouse key is down.
	// if it is: call OnClickEvent

	// for now it can just be whenever the player clicks tho thats fine for now
	if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
		OnClickEvent();
}
