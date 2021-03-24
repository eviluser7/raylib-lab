/*
Mathematical graph functions by eviluser7
(c) 2021

Made with raylib v3.5.0
raylib.com/
*/

#include "raylib.h"
#include <math.h>

/* defines */
#define SCREEN_WIDTH     800
#define SCREEN_HEIGHT    600

/* functions */
void plot(float x, float y, Color color);
void draw(void);
void draw_x_axis(void);
void draw_y_axis(void);

/* formulas 
add your own here! */
void draw_y_eq_x(float a, float b);
void draw_trigo_tan(double step);

/* variables */
const int offset_x = SCREEN_WIDTH / 2;
const int offset_y = SCREEN_HEIGHT / 2;

/* main entry point */
int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Mathematical Graphs");
    SetTargetFPS(24);

    /* sim loop */
    while (!WindowShouldClose()) {
        draw();
    }
}

/* plotting logic */
void plot(float x, float y, Color color)
{
    DrawPixel((offset_x+x), (offset_y-y), color);
}

/* draw current screen */
void draw(void)
{
    BeginDrawing();
    ClearBackground(BLACK);
    draw_x_axis();
    draw_y_axis();
    draw_trigo_tan(0.01);
    EndDrawing();
}

void draw_x_axis(void)
{
    for (int x = -offset_x; x < offset_x; x += 10)
        plot(x, 0, YELLOW);
}

void draw_y_axis(void)
{
    for (int y = -offset_y; y < offset_y; y += 10)
        plot(0, y, YELLOW);
}

/* math functions plotting */
void draw_y_eq_x(float a, float b)
{
    for (float x = -200.0; x < 200.0; x += 0.01) {
        float y = a*x + b;
        plot(x, y, (Color){ 200, 200, 255, 255 });
    }
}

void draw_trigo_tan(double step)
{
    for (double x = -400.0; x < 400.0; x += step) {
        double y = tan(x);
        plot(x, y, (Color){
            (unsigned int)GetRandomValue(0, 255),
            (unsigned int)GetRandomValue(0, 255),
            (unsigned int)GetRandomValue(0, 255),
            255,
        });
    } 
}