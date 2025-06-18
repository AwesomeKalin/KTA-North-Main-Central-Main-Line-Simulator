#ifndef GLOBALS_H
#define GLOBALS_H

#include "stdint.h"
#include "stdbool.h"

//----------------------------------------------------------------------------------
// Types and Structures Definition
//----------------------------------------------------------------------------------
typedef enum Backgrounds {
    bg_night_city_with_street,
    bg_unnamed,
    bg_backdrop1,
    bg_menu,
    bg_screenshot_2024_07_02_at_2,
    bg_station_select,
    bg_screenshot_2024_07_04_at_2,
    bg_route1,
    bg_route2,
    bg_route3,
    bg_route4
} Backgrounds;

//----------------------------------------------------------------------------------
// Global Variables Declaration (shared by several modules)
//----------------------------------------------------------------------------------

// Global Variables
extern Backgrounds currentBackground;
extern bool isDoorOpen;
extern uint8_t route;
extern uint8_t status;
extern char* nextStation;
extern char* text;
extern char* thisStation;
extern uint8_t stationNo;
extern float distance;
extern float speed;

// Global Lists
extern char* list_route1[17];
extern char* list_route2[17];
extern char* list_route3[10];
extern char* list_route4[10];
extern int list_sp1[16];
extern int list_sp2[16];
extern int list_sp3[9];
extern int list_sp4[9];

extern char* tempRoute[17];
extern int tempSP[16];

//----------------------------------------------------------------------------------
// Global Functions Declaration
//----------------------------------------------------------------------------------
void MainMenu(void);
void MainGameStart(void);

#ifdef __cplusplus
}
#endif

#endif