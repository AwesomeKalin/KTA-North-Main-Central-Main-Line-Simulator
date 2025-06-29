#include "raylib.h"
#include "globals.h"
#include "background.h"

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