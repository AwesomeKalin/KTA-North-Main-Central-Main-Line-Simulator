#include "raylib.h"
#include "globals.h"
#include "annoucements.h"

//----------------------------------------------------------------------------------
// Local Variables Definition (local to this module)
//----------------------------------------------------------------------------------
static Sound airport2;
static Sound airporteast;
static Sound binworth;
static Sound conby;
static Sound diplo;
static Sound ferringdon;
static Sound fresh_start_lake1;
static Sound fresh_start_lake2;
static Sound giles;
static Sound happing;
static Sound kapple;
static Sound lefting;
static Sound profacton;
static Sound reckby;
static Sound siu_hor;
static Sound stone_village;
static Sound upnor;

void LoadAnnoucements(void) {
	airport2 = LoadSound("resources/tts/airport2.ogg");
	airporteast = LoadSound("resources/tts/airporteast.ogg");
	binworth = LoadSound("resources/tts/binworth.ogg");
	conby = LoadSound("resources/tts/conby.ogg");
	diplo = LoadSound("resources/tts/diplo.ogg");
	ferringdon = LoadSound("resources/tts/ferringdon.ogg");
	fresh_start_lake1 = LoadSound("resources/tts/fresh_start_lake1.ogg");
	fresh_start_lake2 = LoadSound("resources/tts/fresh_start_lake2.ogg");
	giles = LoadSound("resources/tts/giles.ogg");
	happing = LoadSound("resources/tts/happing.ogg");
	kapple = LoadSound("resources/tts/kapple.ogg");
	lefting = LoadSound("resources/tts/lefting.ogg");
	profacton = LoadSound("resources/tts/profacton.ogg");
	reckby = LoadSound("resources/tts/reckby.ogg");
	siu_hor = LoadSound("resources/tts/siu_hor.ogg");
	stone_village = LoadSound("resources/tts/stone_village.ogg");
	upnor = LoadSound("resources/tts/upnor.ogg");
}

void UnloadAnnoucements(void) {
	UnloadSound(airport2);
	UnloadSound(airporteast);
	UnloadSound(binworth);
	UnloadSound(conby);
	UnloadSound(diplo);
	UnloadSound(ferringdon);
	UnloadSound(fresh_start_lake1);
	UnloadSound(fresh_start_lake2);
	UnloadSound(giles);
	UnloadSound(happing);
	UnloadSound(kapple);
	UnloadSound(lefting);
	UnloadSound(profacton);
	UnloadSound(reckby);
	UnloadSound(siu_hor);
	UnloadSound(stone_village);
	UnloadSound(upnor);
}

void AnnoucementLoop(void) {
	if (!(distance > 5000 && distance < 5150)) return;

	if (nextStation == "哈冰火車站 Happing Train Station") {
		PlaySound(happing);
		return;
	}

	if (nextStation == "迪普綠 Diplo Green") {
		PlaySound(diplo);
		return;
	}

	if (nextStation == "烏普諾 Upnor") {
		PlaySound(upnor);
		return;
	}

	if (nextStation == "費林登 Ferringdon") {
		PlaySound(ferringdon);
		return;
	}

	if (nextStation == "康比 Conby") {
		PlaySound(conby);
		return;
	}

	if (nextStation == "力丁 Lefting") {
		PlaySound(lefting);
		return;
	}

	if (nextStation == "首都國際機場二號大樓 Capital International Airport Terminal 2") {
		PlaySound(airport2);
		return;
	}

	if (nextStation == "機場東 Airport East") {
		PlaySound(airporteast);
		return;
	}

	if (nextStation == "新開始河 Fresh Start Lake") {
		if (route == 1) {
			PlaySound(fresh_start_lake1);
		}
		else {
			PlaySound(fresh_start_lake2);
		}

		return;
	}

	if (nextStation == "兵和 Binworth") {
		PlaySound(binworth);
		return;
	}

	if (nextStation == "加爾斯 Giles") {
		PlaySound(giles);
		return;
	}

	if (nextStation == "蓮比西 Reckby West") {
		PlaySound(reckby);
		return;
	}

	if (nextStation == "石頭鎮 Stone Village") {
		PlaySound(stone_village);
		return;
	}

	if (nextStation == "小鵝河 Siu Hor River") {
		PlaySound(siu_hor);
		return;
	}

	if (nextStation == "博法頓 Profacton") {
		PlaySound(profacton);
		return;
	}

	if (nextStation == "卡波綜合交通樞紐 Kapple Transportation Resort") {
		PlaySound(kapple);
		return;
	}
}