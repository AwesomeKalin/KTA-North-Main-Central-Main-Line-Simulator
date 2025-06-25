#include "raylib.h"
#include "globals.h"
#include "train.h"
#include "stdint.h"
#include "string.h"

#define ARRAY_LEN(x) (sizeof(x) / sizeof((x)[0]))

//----------------------------------------------------------------------------------
// Local Variables Definition (local to this module)
//----------------------------------------------------------------------------------
static uint16_t posX = 0;
static uint16_t posY = 123;
static Rectangle rectangle = { 0, 123, 331, 224 };
static bool visible = false;
static bool isTrainDriving = false;
static bool isDoorOpening = false;
static bool isDoorClosing = false;
static bool isDoorCloseSoundPlaying = false;
static Texture2D train;
static Sound dingDong;
static Sound doors1;
static Sound closing;
static Sound doors2;
static Sound train1;
static Sound train2;
static uint8_t openingFrames = 0;
static const Rectangle lineWrapHelper = { 0, 0, 480, 360 };
static uint8_t textFrames = 0;
static bool keyboardAcceleration = false;
static bool trainSounds = false;
static uint8_t train1Frames = 0;
static bool train2Sounds = false;
static uint8_t train2Frames = 0;
static bool waitForSpeed = false;
static bool waitForCloseToStation = false;

//----------------------------------------------------------------------------------
// Local Functions Declaration
//----------------------------------------------------------------------------------
static void DrawTextBoxed(Font font, const char* text, Rectangle rec, float fontSize, float spacing, bool wordWrap, Color tint);
static void DrawTextBoxedSelectable(Font font, const char* text, Rectangle rec, float fontSize, float spacing, bool wordWrap, Color tint, int selectStart, int selectLength, Color selectTint, Color selectBackTint);

void LoadTrainTextures(void) {
	train = LoadTexture("resources/passenger_train_type_4.png");
}

void LoadTrainAudio(void) {
	dingDong = LoadSound("resources/ding_dong.wav");
	doors1 = LoadSound("resources/doors1.wav");
	closing = LoadSound("resources/closing.wav");
	doors2 = LoadSound("resources/doors2.wav");
    train1 = LoadSound("resources/train1.wav");
    train2 = LoadSound("resources/train2.wav");
}

void UnloadTrainResources(void) {
	UnloadTexture(train);

	UnloadSound(dingDong);
	UnloadSound(doors1);
	UnloadSound(closing);
	UnloadSound(doors2);
    UnloadSound(train1);
    UnloadSound(train2);
}

void TrainLoop(void) {
	if (visible) {
		DrawTexture(train, posX, posY, WHITE);

		if (isTrainDriving) {
			if (!isDoorOpening && !isDoorClosing && !isDoorCloseSoundPlaying) {
				Vector2 mouse = GetMousePosition();
				if (speed <= 0.0f && (IsKeyPressed(KEY_SPACE) || (CheckCollisionPointRec(mouse, rectangle) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) && !isDoorOpening) {
					if (!isDoorOpen) {
						isDoorOpen = true;
						PlaySound(dingDong);
						isDoorOpening = true;
					}
					else {
						PlaySound(closing);
						isDoorClosing = true;
					}
				}
			}

			if (isDoorOpening) {
				if (openingFrames >= 29) {
					PlaySound(doors1);

					isDoorOpening = false;
					openingFrames = 0;

					if (stationNo == ARRAY_LEN(tempRoute)) {
						Win();
						isTrainDriving = false;
					}
				}
				else {
					openingFrames++;
				}
			}

			if (isDoorClosing) {
				if (openingFrames >= 18) {
					PlaySound(doors2);

					isDoorClosing = false;
					openingFrames = 0;
					isDoorCloseSoundPlaying = true;
				}
				else {
					openingFrames++;
				}
			}

			if (isDoorCloseSoundPlaying) {
				if (openingFrames >= 57) {
					isDoorOpen = false;
					isDoorCloseSoundPlaying = false;
				}
				else {
					openingFrames++;
				}
			}
		}

        if (textFrames == 60) {
            strcpy_s(text, MAX_TRAIN_TEXT_LEN, "請按空格鍵或按列車關門。Press Space key to close the train doors.");
            textFrames++;
        }

        if (textFrames < 60) {
            textFrames++;
        }

        if (textFrames == 61 && !isDoorOpen) {
            strcpy_s(text, MAX_TRAIN_TEXT_LEN, "請按→鍵發車。Press → key to accelerate.");
            textFrames++;
            TrainStart();
            waitForSpeed = true;
        }

        if (keyboardAcceleration) {
            if ((IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) && speed < 80.0f && !isDoorOpen) {
                speed += 0.2f;
            }

            if ((IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) && speed > 0.0f && !isDoorOpen) {
                speed -= 0.3f;
            }

            if (speed > 80.0f) {
                speed = 80.0f;
            }

            if (speed < 0.0f) {
                speed = 0.0f;
            }

            distance += speed;
        }

        if (trainSounds) {
            if (train1Frames == 844) {
                train2Sounds = true;
                train2Frames = 0;
            }
            else {
                train1Frames++;
            }
        }

        if (train2Sounds) {
            if (train2Frames == 0) {
                if (distance > 48000.0f && speed == 0.0f) {
                    train2Sounds = false;
                }
                else {
                    if (speed > 0.0f) {
                        PlaySound(train2);
                        train2Frames++;
                    }
                }
            }
            else {
                if (train2Frames != 81) {
                    train2Frames++;
                }
                else {
                    train2Frames = 0;
                }
            }
        }

        if (waitForSpeed && speed > 0) {
            waitForSpeed = false;
            strcpy_s(text, MAX_TRAIN_TEXT_LEN, "--");
            waitForCloseToStation = true;
        }

        if (waitForCloseToStation && distance > tempSP[stationNo] / 2) {
            waitForCloseToStation = false;
            const char* tempText = TextFormat("請適當按←鍵剎車並停在行駛距離%d和%d之間。Press ← key to brake and stop between Distance %d and %d.", tempSP[stationNo] - 1000, tempSP[stationNo], tempSP[stationNo] - 1000, tempSP[stationNo]);
        
            strcpy_s(text, MAX_TRAIN_TEXT_LEN, tempText);
        }

		DrawTextBoxed(font, text, lineWrapHelper, 20.0f, 1.0f, true, WHITE);
        DrawTextEx(font, TextFormat(" % .1f", speed), (Vector2){ 0, 330 }, 30.0f, 1.0f, WHITE);
        DrawTextEx(font, "Speed", (Vector2){ 0, 300 }, 30.0f, 1.0f, WHITE);
        DrawTextEx(font, TextFormat(" % .1f", distance), (Vector2){ 0, 270 }, 30.0f, 1.0f, WHITE);
        DrawTextEx(font, "Distance", (Vector2){ 0, 240 }, 30.0f, 1.0f, WHITE);
        DrawTextEx(font, nextStation, (Vector2){ 0, 210 }, 30.0f, 1.0f, WHITE);
        DrawTextEx(font, "Next Station", (Vector2){ 0, 190 }, 30.0f, 1.0f, WHITE);
	}
}

void TrainGameStart(void) {
	visible = true;
	isTrainDriving = true;

    strcpy_s(text, MAX_TRAIN_TEXT_LEN, "感謝 @LPPTra 、 @Isps170207 和 @KR_11 的原作。Thanks to @LPPTra, @lsps170207 and @KR_11 for the original works.");
    textFrames = 0;
}

void TrainMenu(void) {
	isTrainDriving = false;
	visible = false;
	isDoorOpen = true;
    strcpy_s(text, MAX_TRAIN_TEXT_LEN, "--");
    keyboardAcceleration = false;
}

void TrainTrainStart(void) {
    keyboardAcceleration = true;
    nextStation = tempRoute[stationNo + 1];
    trainSounds = true;
    PlaySound(train1);
}

// Credit for below: Raylib examples

// Draw text using font inside rectangle limits
static void DrawTextBoxed(Font font, const char* text, Rectangle rec, float fontSize, float spacing, bool wordWrap, Color tint) {
	DrawTextBoxedSelectable(font, text, rec, fontSize, spacing, wordWrap, tint, 0, 0, WHITE, WHITE);
}

// Draw text using font inside rectangle limits with support for text selection
static void DrawTextBoxedSelectable(Font font, const char* text, Rectangle rec, float fontSize, float spacing, bool wordWrap, Color tint, int selectStart, int selectLength, Color selectTint, Color selectBackTint) {
    int length = TextLength(text);  // Total length in bytes of the text, scanned by codepoints in loop

    float textOffsetY = 0;          // Offset between lines (on line break '\n')
    float textOffsetX = 0.0f;       // Offset X to next character to draw

    float scaleFactor = fontSize / (float)font.baseSize;     // Character rectangle scaling factor

    // Word/character wrapping mechanism variables
    enum { MEASURE_STATE = 0, DRAW_STATE = 1 };
    int state = wordWrap ? MEASURE_STATE : DRAW_STATE;

    int startLine = -1;         // Index where to begin drawing (where a line begins)
    int endLine = -1;           // Index where to stop drawing (where a line ends)
    int lastk = -1;             // Holds last value of the character position

    for (int i = 0, k = 0; i < length; i++, k++)
    {
        // Get next codepoint from byte string and glyph index in font
        int codepointByteCount = 0;
        int codepoint = GetCodepoint(&text[i], &codepointByteCount);
        int index = GetGlyphIndex(font, codepoint);

        // NOTE: Normally we exit the decoding sequence as soon as a bad byte is found (and return 0x3f)
        // but we need to draw all of the bad bytes using the '?' symbol moving one byte
        if (codepoint == 0x3f) codepointByteCount = 1;
        i += (codepointByteCount - 1);

        float glyphWidth = 0;
        if (codepoint != '\n')
        {
            glyphWidth = (font.glyphs[index].advanceX == 0) ? font.recs[index].width * scaleFactor : font.glyphs[index].advanceX * scaleFactor;

            if (i + 1 < length) glyphWidth = glyphWidth + spacing;
        }

        // NOTE: When wordWrap is ON we first measure how much of the text we can draw before going outside of the rec container
        // We store this info in startLine and endLine, then we change states, draw the text between those two variables
        // and change states again and again recursively until the end of the text (or until we get outside of the container).
        // When wordWrap is OFF we don't need the measure state so we go to the drawing state immediately
        // and begin drawing on the next line before we can get outside the container.
        if (state == MEASURE_STATE)
        {
            // TODO: There are multiple types of spaces in UNICODE, maybe it's a good idea to add support for more
            // Ref: http://jkorpela.fi/chars/spaces.html
            if ((codepoint == ' ') || (codepoint == '\t') || (codepoint == '\n')) endLine = i;

            if ((textOffsetX + glyphWidth) > rec.width)
            {
                endLine = (endLine < 1) ? i : endLine;
                if (i == endLine) endLine -= codepointByteCount;
                if ((startLine + codepointByteCount) == endLine) endLine = (i - codepointByteCount);

                state = !state;
            }
            else if ((i + 1) == length)
            {
                endLine = i;
                state = !state;
            }
            else if (codepoint == '\n') state = !state;

            if (state == DRAW_STATE)
            {
                textOffsetX = 0;
                i = startLine;
                glyphWidth = 0;

                // Save character position when we switch states
                int tmp = lastk;
                lastk = k - 1;
                k = tmp;
            }
        }
        else
        {
            if (codepoint == '\n')
            {
                if (!wordWrap)
                {
                    textOffsetY += (font.baseSize + font.baseSize / 2) * scaleFactor;
                    textOffsetX = 0;
                }
            }
            else
            {
                if (!wordWrap && ((textOffsetX + glyphWidth) > rec.width))
                {
                    textOffsetY += (font.baseSize + font.baseSize / 2) * scaleFactor;
                    textOffsetX = 0;
                }

                // When text overflows rectangle height limit, just stop drawing
                if ((textOffsetY + font.baseSize * scaleFactor) > rec.height) break;

                // Draw selection background
                bool isGlyphSelected = false;
                if ((selectStart >= 0) && (k >= selectStart) && (k < (selectStart + selectLength)))
                {
                    DrawRectangleRec((Rectangle) { rec.x + textOffsetX - 1, rec.y + textOffsetY, glyphWidth, (float)font.baseSize* scaleFactor }, selectBackTint);
                    isGlyphSelected = true;
                }

                // Draw current character glyph
                if ((codepoint != ' ') && (codepoint != '\t'))
                {
                    DrawTextCodepoint(font, codepoint, (Vector2) { rec.x + textOffsetX, rec.y + textOffsetY }, fontSize, isGlyphSelected ? selectTint : tint);
                }
            }

            if (wordWrap && (i == endLine))
            {
                textOffsetY += (font.baseSize + font.baseSize / 2) * scaleFactor;
                textOffsetX = 0;
                startLine = endLine;
                endLine = -1;
                glyphWidth = 0;
                selectStart += lastk - k;
                k = lastk;

                state = !state;
            }
        }

        if ((textOffsetX != 0) || (codepoint != ' ')) textOffsetX += glyphWidth;  // avoid leading spaces
    }
}