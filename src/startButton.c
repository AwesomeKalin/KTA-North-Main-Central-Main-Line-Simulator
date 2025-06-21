#include "raylib.h"
#include "startButton.h"
#include "stdint.h"
#include "globals.h"

//----------------------------------------------------------------------------------
// Local Variables Definition (local to this module)
//----------------------------------------------------------------------------------
static Texture2D false_svg;
static Texture2D true_svg;
static bool visible = true;
static const int16_t posX = 186;
static const int16_t posY = 229;
static const Rectangle button = { 186, 229, 107, 52 };
static bool fadeinComplete = false;
static float alpha = 0.0f;
static uint8_t fadeInTimer = 0;
static bool afterClick = false;
static uint8_t afterClickFrame = 0;

//----------------------------------------------------------------------------------
// Local Functions Declaration
//----------------------------------------------------------------------------------
static void StartButtonOnClick(void);

void LoadStartButtonTextures(void) {
	false_svg = LoadTexture("resources/false.svg.png");
	true_svg = LoadTexture("resources/true.svg.png");
}

void StartButtonLoop(void) {
	if (visible) {
		if (fadeinComplete) {
			Vector2 mouse = GetMousePosition();

			if (CheckCollisionPointRec(mouse, button)) {
				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
					StartButtonOnClick();
					SetMouseCursor(MOUSE_CURSOR_DEFAULT);
					return;
				}

				DrawTexture(true_svg, posX, posY, WHITE);
				SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
			}
			else {
				DrawTexture(false_svg, posX, posY, WHITE);
				SetMouseCursor(MOUSE_CURSOR_DEFAULT);
			}
			return;
		}

		if (fadeInTimer == 45) {
			alpha += 0.04f;
			Color fadeColor = Fade(WHITE, alpha);
			DrawTexture(false_svg, posX, posY, fadeColor);

			if (alpha >= 1.0f) {
				fadeinComplete = true;
			}
			
			return;
		}

		fadeInTimer++;
	}

	if (afterClick) {
		if (afterClickFrame == 3) {
			afterClick = false;
			SelectRoute();
		}
		else {
			afterClickFrame++;
		}
	}
}

void UnloadStartButtonResources(void) {
	UnloadTexture(false_svg);
	UnloadTexture(true_svg);
}

void StartButtonMenu(void) {
	visible = true;
}

void StartButtonTutorial(void) {
	visible = false;
}

static void StartButtonOnClick(void) {
	PlaySound(coin);

	visible = false;
	afterClick = true;
	afterClickFrame = 0;
}