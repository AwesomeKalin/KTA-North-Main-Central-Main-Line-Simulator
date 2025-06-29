#ifndef GLOBALS_H
#define GLOBALS_H
#define MAX_TRAIN_TEXT_LEN 512

#include "stdint.h"
#include "stdbool.h"
#include "raylib.h"
#include "stddef.h"

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
extern char text[MAX_TRAIN_TEXT_LEN];
extern char* thisStation;
extern uint8_t stationNo;
extern float distance;
extern float speed;
extern Sound coin;
extern bool isHoveringButton;
extern Font font;

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
void SetRoute(void);
void Menu(void);
void SelectRoute(void);
void SelectStation(void);
void Tutorial(void);
void Lose(void);
void Win(void);
void TrainButton(void);
void GameStart(void);
void TrainStart(void);
size_t IntArrayLengthUntilZero(const int* arr, size_t max_len);
size_t count_non_null(void* const* array, size_t len);

#ifdef __cplusplus
}
#endif

#endif