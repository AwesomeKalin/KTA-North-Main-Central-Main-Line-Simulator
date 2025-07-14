#include "raylib.h"
#include "globals.h"
#include "background.h"
#include "stdint.h"
#include "math.h"

//----------------------------------------------------------------------------------
// Local Types and Structures Definition
//----------------------------------------------------------------------------------
typedef struct BackgroundClone {
	int16_t posX;
	uint16_t posY;
	bool visible;
	Texture2D* costume;
} BackgroundClone;

//----------------------------------------------------------------------------------
// Local Variables Definition (local to this module)
//----------------------------------------------------------------------------------
static Texture2D ground;
static Texture2D ground2;
static Texture2D ktr_vector;
static Texture2D kapple_transportation_resort_2;
static Texture2D hts_vector;
static Texture2D ape_vector;
static Texture2D airport_east;
static Texture2D happing_train_station_2;
static Texture2D dlg_vector;
static Texture2D lft_vector;
static Texture2D lefting;
static Texture2D upn_vector;
static Texture2D fsl_vector;
static Texture2D bnw_vector;
static Texture2D gls_vector;
static Texture2D fth_vector;
static Texture2D forest_heights_2;
static Texture2D rbw_vector;
static Texture2D reckby_west;
static Texture2D svl_vector;
static Texture2D stone_village;
static Texture2D shr_vector;
static Texture2D siu_hor_river;
static Texture2D giles;
static Texture2D binworth_2;
static Texture2D fresh_start_lake_2;
static Texture2D frd_vector;
static Texture2D ca2_vector;
static Texture2D capital_international_airport_terminal_2_2;
static Texture2D cnb_vector;
static Texture2D pft_vector;
static Texture2D profacton;
static Texture2D conby;
static Texture2D ferringdon;
static Texture2D upnor_2;
static Texture2D diplo_green;
static BackgroundClone clones[1] = { 0 };
static uint8_t cloneCount = 0;
static int16_t posX = 0;
static uint16_t posY = 0;
static Texture2D* currentCostume;
static bool visible = false;
static bool loop = false;

//----------------------------------------------------------------------------------
// Local Functions Declaration
//----------------------------------------------------------------------------------
static Texture2D* GetCostumeByStationName(char* name);

void LoadBackgroundTextures(void) {
	ground = LoadTexture("resources/ground.png");
	ground2 = LoadTexture("resources/ground2.png");
	ktr_vector = LoadTexture("resources/ktr_vector.png");
	kapple_transportation_resort_2 = LoadTexture("resources/kapple_transportation_resort_2.png");
	hts_vector = LoadTexture("resources/hts_vector.png");
	ape_vector = LoadTexture("resources/ape_vector.png");
	airport_east = LoadTexture("resources/airport_east.png");
	happing_train_station_2 = LoadTexture("resources/happing_train_station_2.png");
	dlg_vector = LoadTexture("resources/dlg_vector.png");
	lft_vector = LoadTexture("resources/lft_vector.png");
	lefting = LoadTexture("resources/lefting.png");
	upn_vector = LoadTexture("resources/upn_vector.png");
	fsl_vector = LoadTexture("resources/fsl_vector.png");
	bnw_vector = LoadTexture("resources/bnw_vector.png");
	gls_vector = LoadTexture("resources/gls_vector.png");
	fth_vector = LoadTexture("resources/fth_vector.png");
	forest_heights_2 = LoadTexture("resources/forest_heights_2.png");
	rbw_vector = LoadTexture("resources/rbw_vector.png");
	reckby_west = LoadTexture("resources/reckby_west.png");
	svl_vector = LoadTexture("resources/svl_vector.png");
	stone_village = LoadTexture("resources/stone_village.png");
	shr_vector = LoadTexture("resources/shr_vector.png");
	siu_hor_river = LoadTexture("resources/siu_hor_river.png");
	giles = LoadTexture("resources/giles.png");
	binworth_2 = LoadTexture("resources/binworth_2.png");
	fresh_start_lake_2 = LoadTexture("resources/fresh_start_lake_2.png");
	frd_vector = LoadTexture("resources/frd_vector.png");
	ca2_vector = LoadTexture("resources/ca2_vector.png");
	capital_international_airport_terminal_2_2 = LoadTexture("resources/capital_international_airport_terminal_2_2.png");
	cnb_vector = LoadTexture("resources/cnb_vector.png");
	pft_vector = LoadTexture("resources/pft_vector.png");
	profacton = LoadTexture("resources/profacton.png");
	conby = LoadTexture("resources/conby.png");
	ferringdon = LoadTexture("resources/ferringdon.png");
	upnor_2 = LoadTexture("resources/upnor_2.png");
	diplo_green = LoadTexture("resources/diplo_green.png");
}

void UnloadBackgroundResources(void) {
	UnloadTexture(ground);
	UnloadTexture(ground2);
	UnloadTexture(ktr_vector);
	UnloadTexture(kapple_transportation_resort_2);
	UnloadTexture(hts_vector);
	UnloadTexture(ape_vector);
	UnloadTexture(airport_east);
	UnloadTexture(happing_train_station_2);
	UnloadTexture(dlg_vector);
	UnloadTexture(lft_vector);
	UnloadTexture(lefting);
	UnloadTexture(upn_vector);
	UnloadTexture(fsl_vector);
	UnloadTexture(bnw_vector);
	UnloadTexture(gls_vector);
	UnloadTexture(fth_vector);
	UnloadTexture(forest_heights_2);
	UnloadTexture(rbw_vector);
	UnloadTexture(reckby_west);
	UnloadTexture(svl_vector);
	UnloadTexture(stone_village);
	UnloadTexture(shr_vector);
	UnloadTexture(siu_hor_river);
	UnloadTexture(giles);
	UnloadTexture(binworth_2);
	UnloadTexture(fresh_start_lake_2);
	UnloadTexture(frd_vector);
	UnloadTexture(ca2_vector);
	UnloadTexture(capital_international_airport_terminal_2_2);
	UnloadTexture(cnb_vector);
	UnloadTexture(pft_vector);
	UnloadTexture(profacton);
	UnloadTexture(conby);
	UnloadTexture(ferringdon);
	UnloadTexture(upnor_2);
	UnloadTexture(diplo_green);
}

void BackgroundLoop(void) {
	if (visible) {
		DrawTexture(*currentCostume, posX, posY, WHITE);
		DrawTexture(*clones[0].costume, clones[0].posX, clones[0].posY, WHITE);

		if (loop) {
			if (distance > tempSP[stationNo] - 11000) thisStation = nextStation;
			if (posX < -470 || posX > 470) {
				if ((distance < 200 || distance > tempSP[stationNo] - 7000) && distance < tempSP[stationNo]) {
					status = 1;
				}
				else status = 2;

				if (status == 1) {
					currentCostume = GetCostumeByStationName(thisStation);
				}

				if (status == 2) {
					if (nextStation == "烏普諾 Upnor" ||
						nextStation == "費林登 Ferringdon" ||
						nextStation == "力丁 Lefting" ||
						nextStation == "首都國際機場二號大樓 Capital International Airport Terminal 2" ||
						nextStation == "機場東 Airport East" ||
						nextStation == "新開始河 Fresh Start Lake" ||
						nextStation == "兵和 Binworth" ||
						nextStation == "加爾斯 Giles" ||
						nextStation == "蓮比西 Reckby West"
						) {
						currentCostume = &ground2;
					}
					else {
						currentCostume = &ground;
					}
				}
			}

			if (clones[0].posX < -470 || clones[0].posX > 470) {
				if ((distance < 200 || distance > tempSP[stationNo] - 7000) && distance < tempSP[stationNo]) {
					status = 1;
				}
				else status = 2;

				if (status == 1) {
					clones[0].costume = GetCostumeByStationName(thisStation);
				}

				if (status == 2) {
					if (nextStation == "烏普諾 Upnor" ||
						nextStation == "費林登 Ferringdon" ||
						nextStation == "力丁 Lefting" ||
						nextStation == "首都國際機場二號大樓 Capital International Airport Terminal 2" ||
						nextStation == "機場東 Airport East" ||
						nextStation == "新開始河 Fresh Start Lake" ||
						nextStation == "兵和 Binworth" ||
						nextStation == "加爾斯 Giles" ||
						nextStation == "蓮比西 Reckby West"
						) {
						clones[0].costume = &ground2;
					}
					else {
						clones[0].costume = &ground;
					}
				}
			}

			posX = (480 - js_mod(distance, 960));
			clones[0].posX = (480 - js_mod(distance - 480, 960));
		}
	}
}

void BackgroundGameStart(void) {
	cloneCount++;
	clones[0] = (BackgroundClone){ 480, 0, true, GetCostumeByStationName(tempRoute[stationNo])};

	currentCostume = GetCostumeByStationName(tempRoute[stationNo]);
	distance = 0;
	visible = true;
	loop = true;
}

void BackgroundMenu(void) {
	visible = false;
	posX = 0;
	posY = 0;
	memset(clones, 0, sizeof(clones));
	cloneCount = 0;
}

static Texture2D* GetCostumeByStationName(char* name) {
	if (name == "卡波綜合交通樞紐 Kapple Transportation Resort") {
		return &kapple_transportation_resort_2;
	}
	else if (name == "哈冰火車站 Happing Train Station") {
		return &happing_train_station_2;
	}
	else if (name == "迪普綠 Diplo Green") {
		return &diplo_green;
	}
	else if (name == "烏普諾 Upnor") {
		return &upnor_2;
	}
	else if (name == "費林登 Ferringdon") {
		return &ferringdon;
	}
	else if (name == "康比 Conby") {
		return &conby;
	}
	else if (name == "力丁 Lefting") {
		return &lefting;
	}
	else if (name == "首都國際機場二號大樓 Capital International Airport Terminal 2") {
		return &capital_international_airport_terminal_2_2;
	}
	else if (name == "機場東 Airport East") {
		return &airport_east;
	}
	else if (name == "新開始河 Fresh Start Lake") {
		return &fresh_start_lake_2;
	}
	else if (name == "兵和 Binworth") {
		return &binworth_2;
	}
	else if (name == "加爾斯 Giles") {
		return &giles;
	}
	else if (name == "蓮比西 Reckby West") {
		return &reckby_west;
	}
	else if (name == "石頭鎮 Stone Village") {
		return &stone_village;
	}
	else if (name == "小鵝河 Siu Hor River") {
		return &siu_hor_river;
	}
	else if (name == "博法頓 Profacton") {
		return &profacton;
	}
	else if (name == "樹林山 Forest Heights") {
		return &forest_heights_2;
	}
	else {
		return &kapple_transportation_resort_2;
	}
}