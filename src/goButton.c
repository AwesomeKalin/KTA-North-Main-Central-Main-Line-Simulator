#include "raylib.h"
#include "globals.h"
#include "goButton.h"
#include "stdint.h"

//----------------------------------------------------------------------------------
// Local Variables Definition (local to this module)
//----------------------------------------------------------------------------------
static Texture2D go_false;
static Texture2D go_true;
static bool visible = false;
static uint16_t posX = 337;
static uint16_t posY = 54;
static Rectangle button = { 337, 54, 107, 53 };
static Texture2D* currentCostume;
static bool transition = false;
static uint8_t tFrame = 0;

void LoadGoButtonTextures(void) {
	go_false = LoadTexture("resources/go_false.png");
	go_true = LoadTexture("resources/go_true.png");
	currentCostume = &go_false;
}

void UnloadGoButtonResources(void) {
	UnloadTexture(go_false);
	UnloadTexture(go_true);
}

void GoButtonLoop(void) {
	if (visible) {
		Vector2 mouse = GetMousePosition();
		if (CheckCollisionPointRec(mouse, button)) {
			isHoveringButton = true;
			currentCostume = &go_true;

			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
				PlaySound(coin);
				visible = false;
				transition = true;
				tFrame = 0;
			}
		}
		else {
			currentCostume = &go_false;
		}

		DrawTexture(*currentCostume, posX, posY, WHITE);
	}

	if (transition) {
		if (tFrame == 3) {
			transition = false;
			SelectStation();
		}
		else {
			tFrame++;
		}
	}
}

void GoButtonSelectRoute(void) {
	visible = true;
}

void GoButtonMenu(void) {
	visible = false;
}

void GoButtonTutorial(void) {
	visible = false;
}