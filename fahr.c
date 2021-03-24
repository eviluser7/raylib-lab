/*
Fahrenheit to Celsius calculator and viceversa by eviluser7
(c) 2021

Made with raylib v3.5.0
raylib.com/
*/

#include "raylib.h"
#include <stdio.h>

/* defines */
#define SCREEN_WIDTH    1024
#define SCREEN_HEIGHT    600

/* variables */
float celsius, fahr;
int conversion = 0; /* 0 - f->c; 1 - c->f */

/* functions */

/* fahr to cel */
float f_to_c(float f)
{
    fahr = f;
    celsius = (f - 32.0) * 5.0 / 9.0;
    return celsius;
}

/* cel to fahr */
float c_to_f(float c)
{
    celsius = c;
    fahr = (c * 9/5) + 32;
    return fahr;
}

void init_cel(void)
{
    conversion = 1;
    celsius = 0;
}

void init_fahr(void)
{
    conversion = 0;
    fahr = 0;
}

/* drawing and updating */
void update(void);
void draw(void);

/* main entry point */
int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Temperature Calculator");
    SetTargetFPS(60);
    init_fahr();

    while (!WindowShouldClose()) {
        update();
        draw();
    }

    CloseWindow();
    return 0;
}

/* update the state */
void update(void)
{
    if (conversion == 0) {
        SetWindowTitle("Fahrenheit to Celsius");
        f_to_c(fahr);
    }
    else if (conversion == 1) {
        SetWindowTitle("Celsius to Fahrenheit");
        c_to_f(celsius);
    }
    else conversion = 0;

    /* change modes */
    if (IsKeyPressed(KEY_C)) init_cel();
    if (IsKeyPressed(KEY_F)) init_fahr();

    /* change values */
    if (conversion == 1) {
        if (IsKeyPressed(KEY_UP)) celsius += 0.1;
        else if (IsKeyPressed(KEY_W)) celsius++;
        else if (IsKeyPressed(KEY_DOWN)) celsius -= 0.1;
        else if (IsKeyPressed(KEY_S)) celsius--;
    } else if (conversion == 0) {
        if (IsKeyPressed(KEY_UP)) fahr += 0.1;
        else if (IsKeyPressed(KEY_W)) fahr++;
        else if (IsKeyPressed(KEY_DOWN)) fahr -= 0.1;
        else if (IsKeyPressed(KEY_S)) fahr--;
    }
}

/* draw the current screen */
void draw(void)
{
    BeginDrawing();
    ClearBackground(RAYWHITE);

    /* draw texts */
    if (conversion == 0) {
        DrawText("Fahrenheit to Celsius", 10, 10, 30, BLACK);
        DrawText(FormatText("%.3fF°", fahr), 230, 300, 40, BLACK);
        DrawText(FormatText("%.3fC°", celsius), 660, 300, 40, BLACK);
    }
    else if (conversion == 1) {
        DrawText("Celsius to Fahrenheit", 10, 10, 30, BLACK);
        DrawText(FormatText("%.3fC°", celsius), 230, 300, 40, BLACK);
        DrawText(FormatText("%.3fF°", fahr), 660, 300, 40, BLACK);
    }
    else conversion = 0;

    DrawText("Press C to calculate from Celsius to Fahrenheit", 10, 50, 20, BLACK);
    DrawText("Press F to calculate from Fahrenheit to Celsius", 10, 80, 20, BLACK);
    DrawText("Press the Up or Down arrows to increase / decrease decimals", 10, 110, 20, BLACK);
    DrawText("Press W or S to increase / decrease one degree", 10, 140, 20, BLACK);

    EndDrawing();
}