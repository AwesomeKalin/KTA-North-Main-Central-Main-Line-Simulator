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
#include "globals.h"
#include "sprite2.h"
#include "startButton.h"
#include "text.h"
#include "button1.h"
#include "button2.h"
#include "goButton.h"
#include "stationSelect.h"
#include "locale.h"
#include "train.h"
#include "stddef.h"

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

//----------------------------------------------------------------------------------
// Shared Variables Definition (global)
// NOTE: Those variables are shared between modules through screens.h
//----------------------------------------------------------------------------------


// Global Variables
Backgrounds currentBackground = bg_menu;
bool isDoorOpen = true;
uint8_t route = 3;
uint8_t status = 1;
char* nextStation = "--";
char text[MAX_TRAIN_TEXT_LEN] = "";
char* thisStation = "卡波綜合交通樞紐 Kapple Transportation Resort";
uint8_t stationNo = 1;
float distance = 0.0f;
float speed = 0.0f;
Sound coin;
bool isHoveringButton = false;
Font font;

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

char* tempRoute[17] = { 0 };
int tempSP[16] = { 0 };

//----------------------------------------------------------------------------------
// Local Variables Definition (local to this module)
//----------------------------------------------------------------------------------
static const int screenWidth = 480;
static const int screenHeight = 360;

static Texture2D night_city_with_street_svg;
static Texture2D unnamed;
static Texture2D menu_svg;
static Texture2D screenshot_2024_07_02_at_2;
static Texture2D station_select_svg;
static Texture2D screenshot_2024_07_04_at_2_svg;
static Texture2D route1_svg;
static Texture2D route2_svg;
static Texture2D route3_svg;
static Texture2D route4_svg;

static Music matrix;

//----------------------------------------------------------------------------------
// Local Functions Declaration
//----------------------------------------------------------------------------------
static void UpdateDrawFrame(void);     // Update and draw one frame
static void DrawBackground(void);      // Draws the background
static void LoadGameTextures(void);    // Loads Game Textures
static void LoadGameAudio(void);       // Loads game audio
static void UnloadGameResources(void); // Unloads Game Textures

static void MainMenu(void);            // Menu Event
static void MainGameStart(void);

//----------------------------------------------------------------------------------
// Main entry point
//----------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //---------------------------------------------------------
    InitWindow(screenWidth, screenHeight, "KTA North Main, Central Main Line Simulator");
    setlocale(LC_ALL, "");

    LoadGameTextures();
    font = LoadFontEx("resources/notoSans.ttf", 30, 0, 30890);

    InitAudioDevice();      // Initialize audio device
    LoadGameAudio();

    // Sprite Setup

    SetMusicVolume(matrix, 0.5f);
    PlayMusicStream(matrix);

#if defined(PLATFORM_WEB)
    emscripten_set_main_loop(UpdateDrawFrame, 30, 1);
#else
    SetTargetFPS(30);       // Set our game to run at 30 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        UpdateMusicStream(matrix);
        UpdateDrawFrame();
    }
#endif

    // De-Initialization
    //--------------------------------------------------------------------------------------
    // Unload current screen data before closing
    // Unload global data loaded
    UnloadGameResources();

    CloseAudioDevice();     // Close audio context

    CloseWindow();          // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

// Update and draw game frame
static void UpdateDrawFrame(void)
{
    BeginDrawing();
    ClearBackground(BLANK);
    DrawBackground();

    isHoveringButton = false;

    // Sprite Loops
    Sprite2Loop();
    StartButtonLoop();
    GoButtonLoop();
    StationSelectLoop();
    TrainLoop();
    Button1Loop();
    Button2Loop();
    TextLoop(); // Last thing to process

    if (isHoveringButton) {
        SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
    }
    else {
        SetMouseCursor(MOUSE_CURSOR_DEFAULT);
    }

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

    // Sprites
    LoadStartButtonTextures();
    LoadTextTextures();
    LoadButton1Textures();
    LoadButon2Textures();
    LoadGoButtonTextures();
    LoadStationSelectTextures();
    LoadTrainTextures();
}

static void LoadGameAudio(void) {
    matrix = LoadMusicStream("resources/matrix.mp3");
    matrix.looping = true;

    coin = LoadSound("resources/coin.wav");

    LoadTrainAudio();
}

static void UnloadGameResources(void) {
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

    // Audio
    UnloadMusicStream(matrix);
    UnloadSound(coin);

    // Font
    UnloadFont(font);

    // Sprites
    UnloadStartButtonResources();
    UnloadTextResources();
    UnloadButton1Resources();
    UnloadButton2Resources();
    UnloadGoButtonResources();
    UnloadStationSelectResources();
    UnloadTrainResources();
}

static void MainMenu(void) {
    currentBackground = bg_menu;
    thisStation = "卡波綜合交通樞紐 Kapple Transportation Resort";
    speed = 0;
    TextCopy(text, "");
    nextStation = "--";
    distance = 0;
    stationNo = 1;
}

static void MainGameStart(void) {
    currentBackground = bg_night_city_with_street;
}

void SetRoute(void) {
    Sprite2SetRoute();
}

void SelectRoute(void) {
    Sprite2SelectRoute();
    Button1SelectRoute();
    Button2SelectRoute();
    GoButtonSelectRoute();
}

void SelectStation(void) {
    Sprite2SelectStation();
    Button1SelectStation();
    Button2SelectStation();
    StationSelectSelectStation();
}

void Menu(void) {
    Sprite2Menu();
    MainMenu();
    StartButtonMenu();
    TextMenu();
    Button1Menu();
    Button2Menu();
    GoButtonMenu();
    TrainMenu();
}

void Tutorial(void) {
    StartButtonTutorial();
    GoButtonTutorial();
}

void Lose(void) {
    TextLose();
}

void Win(void) {
    TextWin();
}

void TrainButton(void) {
    Button1TrainButton();
    Button2TrainButton();
}

void GameStart(void) {
    StationSelectGameStart();
    Button1GameStart();
    TrainGameStart();
    MainGameStart();
}

void TrainStart(void) {
    Button1TrainStart();
    TrainTrainStart();
}

size_t IntArrayLengthUntilZero(const int* arr, size_t max_len) {
    size_t i = 0;
    while (i < max_len && arr[i] != 0) i++;
    return i;
}