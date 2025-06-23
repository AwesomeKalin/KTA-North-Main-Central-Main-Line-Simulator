#include "raylib.h"
#include "globals.h"
#include "text.h"
#include "stdint.h"

//----------------------------------------------------------------------------------
// Local Variables Definition (local to this module)
//----------------------------------------------------------------------------------
static Texture2D win_svg;
static Texture2D lose_svg;
static bool visible = false;
static const uint16_t posX = 164;
static const uint16_t posY = 162;
static Texture2D* currentCostume;
static const Rectangle button = { 164, 162, 153, 37 };

void LoadTextTextures(void) {
	win_svg = LoadTexture("resources/win.svg.png");
	lose_svg = LoadTexture("resources/lose.svg.png");
	currentCostume = &lose_svg;
}

void UnloadTextResources(void) {
	UnloadTexture(win_svg);
	UnloadTexture(lose_svg);
}

void TextLoop(void) {
	if (visible) {
		DrawTexture(*currentCostume, posX, posY, WHITE);
		Vector2 mouse = GetMousePosition();
		if (CheckCollisionPointRec(mouse, button)) {
			isHoveringButton = true;

			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
				Menu();
				visible = false;
			}
		}
	}
}

void TextMenu(void) {
	visible = false;
}

void TextLose(void) {
	currentCostume = &lose_svg;
	visible = true;
}

void TextWin(void) {
	currentCostume = &win_svg;
	visible = true;
}