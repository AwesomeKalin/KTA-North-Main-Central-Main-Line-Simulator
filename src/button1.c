#include "raylib.h"
#include "globals.h"
#include "button1.h"
#include "stdint.h"

//----------------------------------------------------------------------------------
// Local Variables Definition (local to this module)
//----------------------------------------------------------------------------------
static Texture2D button1_svg;
static bool visible = false;
static uint16_t posX = 118;
static uint16_t posY = 56;
static Rectangle button = { 118, 56, 64, 64 };
static float size = 1.0f;
static bool isSelecting = false;

void LoadButton1Textures(void) {
	button1_svg = LoadTexture("resources/button1.svg.png");
}

void UnloadButton1Resources(void) {
	UnloadTexture(button1_svg);
}

void Button1Loop(void) {
	if (visible) {
		DrawTextureEx(button1_svg, (Vector2){ posX, posY }, 0.0f, size, WHITE);

		Vector2 mouse = GetMousePosition();
		if (CheckCollisionPointRec(mouse, button)) {
			isHoveringButton = true;

			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
				if (isSelecting) {
					SetRoute();
					PlaySound(coin);

					if (route < 2) {
						route = 4;
					}
					else {
						route--;
					}
				}
				else {
					if (speed > 0.0f && !isDoorOpen) {
						speed -= 0.3f;
					}
				}
			}
		}
	}
}

void Button1SelectStation(void) {
	visible = false;
}

void Button1SelectRoute(void) {
	posX = 41;
	posY = 266;
	size = 0.75f;
	button = (Rectangle){ 41, 266, 48, 48 };

	visible = true;
	isSelecting = true;
}

void Button1Menu(void) {
	isDoorOpen = true;
	visible = false;
}

void Button1TrainButton(void) {
	posX = 118;
	posY = 56;
	size = 1.0f;
	button = (Rectangle){ 118, 56, 64, 64 };

	visible = true;
	isSelecting = false;
}

void Button1GameStart(void) {
	TrainButton();
}

void Button1TrainStart(void) {
	TrainButton();
}