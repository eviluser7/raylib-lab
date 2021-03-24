/*
Height simulation by eviluser7
(c) 2021

Made with raylib v3.5.0
raylib.com/
*/

#include "raylib.h"

#define SCREEN_WIDTH    1024
#define SCREEN_HEIGHT    600
#define COLORS            26

#define MAX_HEIGHT      230
#define MIN_HEIGHT      120

/* functions declaration */
void update(void);
void draw(void);

/* variables */
int selection = 0; /* 0 - blue rect, 1 - pink rect */
int measure_unit = 0; /* 0 - cm, 1 - in */
int width = 35;
int height_rect1 = 160;
int height_rect2 = 160; /* these two can change */
Vector2 rect1;
Vector2 rect2;

/* main entry point */
int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Stretching rectangles");
    SetTargetFPS(120);

    /* initialize some rectangle values */
    rect1.x = 400;
    rect1.y = 400;

    rect2.x = 500;
    rect2.y = 400;

    /* sim loop */
    while (!WindowShouldClose()) {
        update();
        draw();
    }

    CloseWindow();
    return 0;
}

/* update state */
void update(void)
{
    if (IsKeyDown(KEY_UP) && height_rect1 < MAX_HEIGHT) {
        height_rect1++;
        rect1.y--;
    } else if (IsKeyDown(KEY_DOWN) && height_rect1 > MIN_HEIGHT) {
        height_rect1--;
        rect1.y++;
    }

    if (IsKeyDown(KEY_W) && height_rect2 < MAX_HEIGHT) {
        height_rect2++;
        rect2.y--;
    } else if (IsKeyDown(KEY_S) && height_rect2 > MIN_HEIGHT) {
        height_rect2--;
        rect2.y++;
    }
}

/* draw frame */
void draw(void)
{
    BeginDrawing();
    ClearBackground(RAYWHITE);

    /* draw the rectangles */
    int new_y1 = (height_rect1 + rect1.y) - height_rect1;
    DrawRectangle(rect1.x, new_y1, width, height_rect1, BLUE); /* rect 1 */

    int new_y2 = (height_rect2 + rect2.y) - height_rect2;
    DrawRectangle(rect2.x, new_y2, width, height_rect2, PINK); /* rect 2 */

    /* text drawing */

    /* presentation */
    DrawText("Height simulation", 10, 10, 30, BLACK);
    DrawText("Max is 230cm / 90.55in", 10, 40, 30, BLACK);
    DrawText("Min is 120cm / 47.24in", 10, 70, 30, BLACK);

    /* information */
    if (measure_unit == 0) { /* cm */
        DrawText(FormatText("%dcm", height_rect1), rect1.x-100, 500, 20, BLACK);
        DrawText(FormatText("%dcm", height_rect2), rect2.x+70, 500, 20, BLACK);
    }

    EndDrawing();
}