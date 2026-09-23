#include "../graphics.h"
#include <stdio.h>
#include "pico/stdlib.h"

typedef uint16_t color_t;

int
init_graphics()
{
    puts("Init graphics");
    return 0;
}

void
begin_drawing()
{
    puts("Begin drawing");
}

void
clear_screen(color_t color)
{
    puts("Clear the screen");
}

void
draw_rect(int x, int y, int w, int h, color_t color)
{
    puts("Draw a rectangle");
}

void
fill_rect(int x, int y, int w, int h, color_t color)
{
    puts("Fill a rectangle");
}

void
draw_circle(int cx, int cy, int r, color_t color)
{
    puts("Draw a circle");
}

void
fill_circle(int cx, int cy, int r, color_t color)
{
    puts("Fill a circle");
}

void
draw_triangle(int x1, int y1, int x2, int y2, int x3, int y3, color_t color)
{
    puts("Draw a triangle");
}

void
fill_triangle(int x1, int y1, int x2, int y2, int x3, int y3, color_t color)
{
    puts("Fill a triangle");
}

void
end_drawing()
{
    puts("End drawing");
}

void
deinit_graphics()
{
    puts("Deinit the graphics");
}

