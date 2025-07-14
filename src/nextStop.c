#include "raylib.h"
#include "globals.h"
#include "nextStop.h"
#include "stdint.h"
#include "math.h"

//----------------------------------------------------------------------------------
// Local Variables Definition (local to this module)
//----------------------------------------------------------------------------------
static Texture2D thisStationTex;
static Texture2D nextStationTex;
static Texture2D costume2;
static Texture2D costume3;
static Texture2D costume5;
static Texture2D costume6;
static bool active = false;

//----------------------------------------------------------------------------------
// Local Functions Declaration
//----------------------------------------------------------------------------------
static Texture2D routeChecker(int8_t pos);

void LoadNextStopTextures(void) {
	thisStationTex = LoadTexture("resources/thisStation.png");
	nextStationTex = LoadTexture("resources/nextStation.png");
	costume2 = LoadTexture("resources/costume2.png");
	costume3 = LoadTexture("resources/costume3.png");
	costume5 = LoadTexture("resources/costume5.png");
	costume6 = LoadTexture("resources/costume6.png");
}

void UnloadNextStopResources(void) {
	UnloadTexture(thisStationTex);
	UnloadTexture(nextStationTex);
	UnloadTexture(costume2);
	UnloadTexture(costume3);
	UnloadTexture(costume5);
	UnloadTexture(costume6);
}

void NextStopLoop(void) {
	if (active) {
		DrawTexture(routeChecker(1), 436, 83, WHITE);
		DrawTexture(routeChecker(2), 436, 114, WHITE);
		DrawTexture(routeChecker(3), 436, 145, WHITE);
		DrawTexture(routeChecker(4), 436, 176, WHITE);
		DrawTexture(routeChecker(5), 436, 207, WHITE);
		DrawTexture(routeChecker(6), 436, 238, WHITE);
		DrawTexture(thisStationTex, 350, 52, WHITE);
		DrawTexture(nextStationTex, 348, 269, WHITE);
	}
}

void NextStopGameStart(void) {
	active = true;
}

void NextStopMenu(void) {
	active = false;
}

static Texture2D routeChecker(int8_t pos) {
	if (distance > round((pos / 6.5) * tempSP[stationNo])) {
		if ((route == 1 && getPositionOfValueInCharArray(list_route1, nextStation, 17) > 9) || (route == 2 && getPositionOfValueInCharArray(list_route2, nextStation, 17) < 9)) {
			return costume6;
		} else return costume2;
	}
	else {
		if ((route == 1 && getPositionOfValueInCharArray(list_route1, nextStation, 17) > 9) || (route == 2 && getPositionOfValueInCharArray(list_route2, nextStation, 17) < 9)) {
			return costume5;
		} else return costume3;
	}
}