#include "raylib.h"
#include "globals.h"
#include "button2.h"
#include "stdint.h"

//----------------------------------------------------------------------------------
// Local Variables Definition (local to this module)
//----------------------------------------------------------------------------------
static Texture2D button2_svg;
static bool visible = false;
static uint16_t posX = 233;
static uint16_t posY = 56;
static Rectangle button = { 233, 56, 64, 64 };
static float size = 1.0f;
static bool isSelectingRoute = false;

void LoadButon2Textures(void) {
	button2_svg = LoadTexture("resources/button2.svg.png");
}

void UnloadButton2Resources(void) {
	UnloadTexture(button2_svg);
}

void Button2Loop(void) {
	if (visible) {
		DrawTextureEx(button2_svg, (Vector2) { posX, posY }, 0.0f, size, WHITE);

		Vector2 mouse = GetMousePosition();

		if (CheckCollisionPointRec(mouse, button)) {
			isHoveringButton = true;

			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
				if (isSelectingRoute) {
					SetRoute();
					PlaySound(coin);
					if (route > 3) {
						route = 1;
					}
					else {
						route++;
					}
				}
				else {
					if (speed < 80.0f && isDoorOpen == false) speed += 0.2f;
				}
			}
		}
	}
}

void Button2SelectRoute(void) {
	posX = 106;
	posY = 266;
	size = 0.75f;
	button = (Rectangle){ 106, 266, 48, 48 };

	visible = true;
	isSelectingRoute = true;
}

void Button2Menu(void) {
	visible = false;
}

void Button2SelectStation(void) {
	isSelectingRoute = false;
	visible = false;
}

void Button2TrainButton(void) {
	posX = 233;
	posY = 56;
	size = 1.0f;
	button = (Rectangle){ 233, 56, 64, 64 };

	visible = true;
	isSelectingRoute = false;
}