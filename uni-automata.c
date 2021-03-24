/*
1D cellular automata by fedel
github.com/fedel

Made with raylib v3.5.0
raylib.com/
*/

#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include "raylib.h"

/* defines */
#define WIDTH   1024
#define HEIGHT   600

/* functions */
int neighbors(int *universe, int pos)
{
    int llleft = universe[pos - 3 >= 0 ? pos - 3 : WIDTH + pos - 3];
    int lleft = universe[pos - 2 >= 0 ? pos - 2 : WIDTH + pos - 2];
    int rright = universe[pos + 2 % WIDTH];
    int rrright = universe[pos + 3 % WIDTH];

    int left = universe[pos == 0 ? WIDTH - 1 : pos - 1];
    int right = universe[pos == WIDTH - 1 ? 0 : pos + 1];
    return llleft * lleft + left + right + rright * rrright;
}

int rule(int curr, int neighbors)
{
    if (curr == 0) {
        if (neighbors == 1) return 1;
        else return 0;
    } else if (curr == 1) {
        if (neighbors == 1 || neighbors == 0) return 1;
        else return 0;
    }

    /* illegal value is entered */
    exit(1);
}

void universe_tick(int *universe, int *universe_new)
{
    for (int i = 0; i < WIDTH; i++) {
        int curr = universe[i];
        int n = neighbors(universe, i);
        int new = rule(curr, n);
        universe_new[i] = new;
    }
}

void universe_copy(int *from, int *to)
{
    for (int i = 0; i < WIDTH; i++) to[i] = from[i];
}

void universe_draw(int *universe, int line)
{
    for (int i = 0; i < WIDTH; i++) DrawPixel(i, line, universe[i] == 0 ? BLACK : BLUE);
}

/* main entry point */
int main(void)
{
    int universe[WIDTH] = { 0 };
    int universe_new[WIDTH] = { 0 };
    int line = 0;

    universe[10] = 1;
    universe[11] = 1;
    universe[12] = 1;
    universe[14] = 1;
    universe[16] = 1;

    InitWindow(WIDTH, HEIGHT, "1D Automata");
    SetTargetFPS(30);
    
    /* sim loop */
    while (!WindowShouldClose()) {
        BeginDrawing();
        for (int j = 0; j < 5; j++) {
            universe_tick(universe, universe_new);
            universe_copy(universe_new, universe);
            universe_draw(universe, line % HEIGHT);
            line++;
        }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
