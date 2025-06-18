/*******************************************************************************************
*
*   raylib game template
*
*   KTA 北幹、中央幹綫模擬 KTA North Main, Central Main Line Simulator
*   <Game description>
*
*   This game has been created using raylib (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*
********************************************************************************************/

#include "raylib.h"
#include "stdint.h"

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

enum Backgrounds {
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
};

//----------------------------------------------------------------------------------
// Shared Variables Definition (global)
// NOTE: Those variables are shared between modules through screens.h
//----------------------------------------------------------------------------------

// Backgrounds
Texture2D night_city_with_street_svg;
Texture2D unnamed;
Texture2D menu_svg;
Texture2D screenshot_2024_07_02_at_2;
Texture2D station_select_svg;
Texture2D screenshot_2024_07_04_at_2_svg;
Texture2D route1_svg;
Texture2D route2_svg;
Texture2D route3_svg;
Texture2D route4_svg;
enum Backgrounds currentBackground = bg_menu;

// Global Variables
bool isDoorOpen = true;
uint8_t route = 3;
uint8_t status = 1;
char* nextStation = "--";
char* text = "";
char* thisStation = "卡波綜合交通樞紐 Kapple Transportation Resort";
uint8_t stationNo = 1;
float distance = 0.0f;
float speed = 0.0f;

// Global Lists
char* list_route1[] = {
    "卡波綜合交通樞紐 Kapple Transportation Resort",
    "哈冰火車站 Happing Train Station",
    "迪普綠 Diplo Green",
    "烏普諾 Upnor",
    "費林登 Ferringdon",
    "康比 Conby",
    "力丁 Lefting",
    "首都國際機場二號大樓 Capital International Airport Terminal 2",
    "機場東 Airport East",
    "新開始河 Fresh Start Lake",
    "兵和 Binworth",
    "加爾斯 Giles",
    "蓮比西 Reckby West",
    "石頭鎮 Stone Village",
    "小鵝河 Siu Hor River",
    "博法頓 Profacton",
    "樹林山 Forest Heights"
};

char* list_route2[] = {
    "樹林山 Forest Heights",
    "博法頓 Profacton",
    "小鵝河 Siu Hor River",
    "石頭鎮 Stone Village",
    "蓮比西 Reckby West",
    "加爾斯 Giles",
    "兵和 Binworth",
    "新開始河 Fresh Start Lake",
    "機場東 Airport East",
    "首都國際機場二號大樓 Capital International Airport Terminal 2",
    "力丁 Lefting",
    "康比 Conby",
    "費林登 Ferringdon",
    "烏普諾 Upnor",
    "迪普綠 Diplo Green",
    "哈冰火車站 Happing Train Station",
    "卡波綜合交通樞紐 Kapple Transportation Resort",
};

char* list_route3[] = {
    "卡波綜合交通樞紐 Kapple Transportation Resort",
    "哈冰火車站 Happing Train Station",
    "迪普綠 Diplo Green",
    "烏普諾 Upnor",
    "費林登 Ferringdon",
    "康比 Conby",
    "力丁 Lefting",
    "首都國際機場二號大樓 Capital International Airport Terminal 2",
    "機場東 Airport East",
    "新開始河 Fresh Start Lake"
};

char* list_route4[] = {
    "新開始河 Fresh Start Lake",
    "機場東 Airport East",
    "首都國際機場二號大樓 Capital International Airport Terminal 2",
    "力丁 Lefting",
    "康比 Conby",
    "費林登 Ferringdon",
    "烏普諾 Upnor",
    "迪普綠 Diplo Green",
    "哈冰火車站 Happing Train Station",
    "卡波綜合交通樞紐 Kapple Transportation Resort"
};

int list_sp1[] = {
    110000,
    70000,
    85000,
    90000,
    80000,
    35000,
    40000,
    30000,
    80000,
    55000,
    54000,
    53000,
    28000,
    48000,
    34000,
    30000
};

int list_sp2[] = {
    30000,
    34000,
    48000,
    28000,
    53000,
    54000,
    55000,
    80000,
    30000,
    40000,
    35000,
    80000,
    90000,
    85000,
    70000,
    110000
};

int list_sp3[] = {
    110000,
    70000,
    85000,
    90000,
    80000,
    35000,
    40000,
    30000,
    80000
};

int list_sp4[] = {
    80000,
    30000,
    40000,
    35000,
    80000,
    90000,
    85000,
    70000,
    110000
};

//----------------------------------------------------------------------------------
// Local Variables Definition (local to this module)
//----------------------------------------------------------------------------------
static const int screenWidth = 480;
static const int screenHeight = 360;

//----------------------------------------------------------------------------------
// Local Functions Declaration
//----------------------------------------------------------------------------------
static void UpdateDrawFrame(void);    // Update and draw one frame
static void DrawBackground(void);     // Draws the background
static void LoadGameTextures(void);   // Loads Game Textures
static void UnloadGameTextures(void); // Unloads Game Textures
static void UnloadVars(void);         // Unloads Variables

//----------------------------------------------------------------------------------
// Main entry point
//----------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //---------------------------------------------------------
    InitWindow(screenWidth, screenHeight, "KTA North Main, Central Main Line Simulator");

    LoadGameTextures();

    InitAudioDevice();      // Initialize audio device

#if defined(PLATFORM_WEB)
    emscripten_set_main_loop(UpdateDrawFrame, 30, 1);
#else
    SetTargetFPS(30);       // Set our game to run at 30 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        UpdateDrawFrame();
    }
#endif

    // De-Initialization
    //--------------------------------------------------------------------------------------
    // Unload current screen data before closing
    // Unload global data loaded
    UnloadGameTextures();
    UnloadVars();

    CloseAudioDevice();     // Close audio context

    CloseWindow();          // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

// Update and draw game frame
static void UpdateDrawFrame(void)
{
    BeginDrawing();

    DrawBackground();

    EndDrawing();
}

static void DrawBackground(void) {
    switch (currentBackground) {
    case bg_night_city_with_street:
        DrawTexture(night_city_with_street_svg, 0, 0, WHITE);
        break;

    case bg_unnamed:
        DrawTexture(unnamed, 0, 0, WHITE);
        break;

    case bg_backdrop1:
        ClearBackground(WHITE);
        break;

    case bg_menu:
        DrawTexture(menu_svg, 0, 0, WHITE);
        break;

    case bg_screenshot_2024_07_02_at_2:
        DrawTexture(screenshot_2024_07_02_at_2, 0, 0, WHITE);
        break;

    case bg_station_select:
        DrawTexture(station_select_svg, 0, 0, WHITE);
        break;

    case bg_screenshot_2024_07_04_at_2:
        DrawTexture(screenshot_2024_07_04_at_2_svg, 0, 0, WHITE);
        break;

    case bg_route1:
        DrawTexture(route1_svg, 0, 0, WHITE);
        break;

    case bg_route2:
        DrawTexture(route2_svg, 0, 0, WHITE);
        break;

    case bg_route3:
        DrawTexture(route3_svg, 0, 0, WHITE);
        break;

    case bg_route4:
        DrawTexture(route4_svg, 0, 0, WHITE);
        break;
    };
}

static void LoadGameTextures(void) {
    // Backgrounds
    night_city_with_street_svg = LoadTexture("resources/night_city_with_street.svg.png");
    unnamed = LoadTexture("resources/unnamed.svg.png");
    menu_svg = LoadTexture("resources/menu.svg.png");
    screenshot_2024_07_02_at_2 = LoadTexture("resources/screenshot_2024_07_02_at_2.png");
    station_select_svg = LoadTexture("resources/station_select.svg.png");
    screenshot_2024_07_04_at_2_svg = LoadTexture("resources/screenshot_2024_07_04_at_2.svg.png");
    route1_svg = LoadTexture("resources/route1.svg.png");
    route2_svg = LoadTexture("resources/route2.svg.png");
    route3_svg = LoadTexture("resources/route3.svg.png");
    route4_svg = LoadTexture("resources/route4.svg.png");
}

static void UnloadGameTextures(void) {
    // Backgrounds
    UnloadTexture(night_city_with_street_svg);
    UnloadTexture(unnamed);
    UnloadTexture(menu_svg);
    UnloadTexture(screenshot_2024_07_02_at_2);
    UnloadTexture(station_select_svg);
    UnloadTexture(screenshot_2024_07_04_at_2_svg);
    UnloadTexture(route1_svg);
    UnloadTexture(route2_svg);
    UnloadTexture(route3_svg);
    UnloadTexture(route4_svg);
}

static void UnloadVars(void) {
    // Global Variables
    free(thisStation);
    free(text);
    free(nextStation);

    // Global Lists
    free(list_route1);
    free(list_route2);
    free(list_route3);
    free(list_route4);
}