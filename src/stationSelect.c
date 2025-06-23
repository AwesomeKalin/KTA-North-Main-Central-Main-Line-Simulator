#include "raylib.h"
#include "globals.h"
#include "stationSelect.h"
#include "stdint.h"

#define ARRAY_LEN(x) (sizeof(x) / sizeof((x)[0]))
#define STATION_CHECK(x,y) (strcmp(tempRoute[x], y) == 0)

//----------------------------------------------------------------------------------
// Local Types and Structures Definition
//----------------------------------------------------------------------------------
typedef struct StationSelectClone {
	Rectangle rectangle;
	bool visible;
	Texture2D* costume;
	uint8_t stationNo;
} StationSelectClone;

//----------------------------------------------------------------------------------
// Local Variables Definition (local to this module)
//----------------------------------------------------------------------------------
static Texture2D kappleTransportationResort;
static Texture2D happingTrainStation;
static Texture2D diploGreen;
static Texture2D upnor;
static Texture2D ferringdon;
static Texture2D conby;
static Texture2D lefting;
static Texture2D captialInternationalAirportTerminal2;
static Texture2D airportEast;
static Texture2D freshStartLake;
static Texture2D binworth;
static Texture2D giles;
static Texture2D reckbyWest;
static Texture2D stoneVillage;
static Texture2D siuHorRiver;
static Texture2D profaction;
static Texture2D forestHeights;
static StationSelectClone clones[17] = { 0 };
static uint8_t cloneAmount = 0;

void LoadStationSelectTextures(void) {
	kappleTransportationResort = LoadTexture("resources/kapple_transportation_resort.png");
	happingTrainStation = LoadTexture("resources/happing_train_station.png");
	diploGreen = LoadTexture("resources/diplo_green_2.png");
	upnor = LoadTexture("resources/upnor.png");
	ferringdon = LoadTexture("resources/ferringdon_2.png");
	conby = LoadTexture("resources/conby_2.png");
	lefting = LoadTexture("resources/lefting_2.png");
	captialInternationalAirportTerminal2 = LoadTexture("resources/capital_international_airport_terminal_2.png");
	airportEast = LoadTexture("resources/airport_east_2.png");
	freshStartLake = LoadTexture("resources/fresh_start_lake.png");
	binworth = LoadTexture("resources/binworth.png");
	giles = LoadTexture("resources/giles_2.png");
	reckbyWest = LoadTexture("resources/reckby_west_2.png");
	stoneVillage = LoadTexture("resources/stone_village_2.png");
	siuHorRiver = LoadTexture("resources/siu_hor_river_2.png");
	profaction = LoadTexture("resources/profacton_2.png");
	forestHeights = LoadTexture("resources/forest_heights.png");
}

void UnloadStationSelectResources(void) {
	UnloadTexture(kappleTransportationResort);
	UnloadTexture(happingTrainStation);
	UnloadTexture(diploGreen);
	UnloadTexture(upnor);
	UnloadTexture(ferringdon);
	UnloadTexture(conby);
	UnloadTexture(lefting);
	UnloadTexture(captialInternationalAirportTerminal2);
	UnloadTexture(airportEast);
	UnloadTexture(freshStartLake);
	UnloadTexture(binworth);
	UnloadTexture(giles);
	UnloadTexture(reckbyWest);
	UnloadTexture(stoneVillage);
	UnloadTexture(siuHorRiver);
	UnloadTexture(profaction);
	UnloadTexture(forestHeights);
}

void StationSelectLoop(void) {
	for (uint8_t i = 0; i < cloneAmount; i++) {
		if (clones[i].visible) {
			DrawTexture(*clones[i].costume, clones[i].rectangle.x, clones[i].rectangle.y, WHITE);

			Vector2 mouse = GetMousePosition();
			if (CheckCollisionPointRec(mouse, clones[i].rectangle)) {
				isHoveringButton = true;
				DrawTextEx(font, tempRoute[clones[i].stationNo], (Vector2){ (480 - MeasureTextEx(font, tempRoute[clones[i].stationNo], 20, 1).x) / 2, 295 }, 20, 1, BLACK);
			}
		}
	}
}

void StationSelectSelectStation(void) {
	for (uint8_t i = 0; i < IntArrayLengthUntilZero(tempRoute, ARRAY_LEN(tempRoute)); i++) {
		if (STATION_CHECK(i, "卡波綜合交通樞紐 Kapple Transportation Resort")) {
			clones[i] = (StationSelectClone){ (Rectangle){ 46, 49, 25, 56 }, true, &kappleTransportationResort, i};
		}
		else if (STATION_CHECK(i, "哈冰火車站 Happing Train Station")) {
			clones[i] = (StationSelectClone){ (Rectangle) { 134, 59, 26, 48 }, true, &happingTrainStation, i };
		}
		else if (STATION_CHECK(i, "迪普綠 Diplo Green")) {
			clones[i] = (StationSelectClone){ (Rectangle) { 162, 77, 30, 35 }, true, &diploGreen, i };
		}
		else if (STATION_CHECK(i, "烏普諾 Upnor")) {
			clones[i] = (StationSelectClone){ (Rectangle) { 157, 130, 32, 23 }, true, &upnor, i };
		}
		else if (STATION_CHECK(i, "費林登 Ferringdon")) {
			clones[i] = (StationSelectClone){ (Rectangle) { 163, 178, 25, 24 }, true, &ferringdon, i };
		}
		else if (STATION_CHECK(i, "康比 Conby")) {
			clones[i] = (StationSelectClone){ (Rectangle) { 166, 215, 30, 22 }, true, &conby, i };
		}
		else if (STATION_CHECK(i, "力丁 Lefting")) {
			clones[i] = (StationSelectClone){ (Rectangle) { 178, 238, 23, 16 }, true, &lefting, i };
		}
		else if (STATION_CHECK(i, "首都國際機場二號大樓 Capital International Airport Terminal 2")) {
			clones[i] = (StationSelectClone){ (Rectangle) { 189, 256, 12, 25 }, true, &captialInternationalAirportTerminal2, i };
		}
		else if (STATION_CHECK(i, "機場東 Airport East")) {
			clones[i] = (StationSelectClone){ (Rectangle) { 203, 253, 19, 21 }, true, &airportEast, i };
		}
		else if (STATION_CHECK(i, "新開始河 Fresh Start Lake")) {
			clones[i] = (StationSelectClone){ (Rectangle) { 227, 236, 33, 59 }, true, &freshStartLake, i };
		}
		else if (STATION_CHECK(i, "兵和 Binworth")) {
			clones[i] = (StationSelectClone){ (Rectangle) { 274, 250, 22, 33 }, true, &binworth, i };
		}
		else if (STATION_CHECK(i, "加爾斯 Giles")) {
			clones[i] = (StationSelectClone){ (Rectangle) { 308, 253, 24, 30 }, true, &giles, i };
		}
		else if (STATION_CHECK(i, "蓮比西 Reckby West")) {
			clones[i] = (StationSelectClone){ (Rectangle) { 343, 250, 21, 35 }, true, &reckbyWest, i };
		}
		else if (STATION_CHECK(i, "石頭鎮 Stone Village")) {
			clones[i] = (StationSelectClone){ (Rectangle) { 366, 248, 16, 39 }, true, &stoneVillage, i };
		}
		else if (STATION_CHECK(i, "小鵝河 Siu Hor River")) {
			clones[i] = (StationSelectClone){ (Rectangle) { 387, 251, 22, 33 }, true, &siuHorRiver, i };
		}
		else if (STATION_CHECK(i, "博法頓 Profacton")) {
			clones[i] = (StationSelectClone){ (Rectangle) { 411, 256, 10, 26 }, true, &profaction, i };
		}
		else if (STATION_CHECK(i, "樹林山 Forest Heights")) {
			clones[i] = (StationSelectClone){ (Rectangle) { 422, 248, 24, 37 }, true, &forestHeights, i };
		}

		cloneAmount++;
	}
}