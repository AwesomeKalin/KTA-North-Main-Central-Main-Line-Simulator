#include "stdint.h"
#include "globals.h"
#include "sprite2.h"
#include "string.h"

//----------------------------------------------------------------------------------
// Local Variables Definition (local to this module)
//----------------------------------------------------------------------------------
static bool isBackgroundLoop = false;

//----------------------------------------------------------------------------------
// Local Functions Declaration
//----------------------------------------------------------------------------------
static void putRouteInTempRoute(int amountOfStations);
static void setStationPositions(int amount);

void Sprite2SelectRoute(void) {
	route = 1;
	SetRoute();
	isBackgroundLoop = true;
}

void Sprite2Loop(void) {
	if (isBackgroundLoop) {
		currentBackground = route + 6;
	};
}

void Sprite2SelectStation(void) {
	isBackgroundLoop = false;
	currentBackground = bg_station_select;
}

void Sprite2SetRoute(void) {
	memset(tempRoute, 0, sizeof(tempRoute));
	memset(tempSP, 0, sizeof(tempSP));

	switch (route) {
		case 1:
			putRouteInTempRoute(17);
			setStationPositions(16);
			break;

		case 2:
			putRouteInTempRoute(17);
			setStationPositions(16);
			break;

		case 3:
			putRouteInTempRoute(10);
			setStationPositions(9);
			break;

		case 4:
			putRouteInTempRoute(10);
			setStationPositions(9);
			break;
	}
}

void Sprite2Menu(void) {
	memset(tempRoute, 0, sizeof(tempRoute));
	memset(tempSP, 0, sizeof(tempSP));
}

static void putRouteInTempRoute(int amountOfStations) {
	for (uint8_t i = 0; i < amountOfStations; i++) {
		if (route == 1) tempRoute[i] = list_route1[i];
		if (route == 2) tempRoute[i] = list_route2[i];
		if (route == 3) tempRoute[i] = list_route3[i];
		if (route == 4) tempRoute[i] = list_route4[i];
	}
}

static void setStationPositions(int amount) {
	for (uint8_t i = 0; i < amount; i++) {
		if (route == 1) tempSP[i] = list_sp1[i];
		if (route == 2) tempSP[i] = list_sp2[i];
		if (route == 3) tempSP[i] = list_sp3[i];
		if (route == 4) tempSP[i] = list_sp4[i];
	}
}