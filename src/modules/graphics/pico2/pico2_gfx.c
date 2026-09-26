#include "../graphics.h"
#include <stdio.h>
#include "pico/stdlib.h"
#include "LCD_1in3.h"

#define INFO "INFO: "

typedef uint16_t color_t;

int
init_graphics()
{
    LCD_1IN3_Init(HORIZONTAL);
    return 0;
}

void
begin_drawing()
{
    puts(INFO "Begin drawing");
}

void
clear_screen(color_t color)
{
    puts(INFO "Clear the screen");
}

void
draw_rect(int x, int y, int w, int h, color_t color)
{
    puts(INFO "Draw a rectangle");
}

void
fill_rect(int x, int y, int w, int h, color_t color)
{
    puts(INFO "Fill a rectangle");
}

void
draw_circle(int cx, int cy, int r, color_t color)
{
    puts(INFO "Draw a circle");
}

void
fill_circle(int cx, int cy, int r, color_t color)
{
    LCD_1IN3_DisplayPoint(cx, cy, color);
    puts("Fill a circle");
}

void
draw_triangle(int x1, int y1, int x2, int y2, int x3, int y3, color_t color)
{
    puts(INFO "Draw a triangle");
}

void
fill_triangle(int x1, int y1, int x2, int y2, int x3, int y3, color_t color)
{
    puts(INFO "Fill a triangle");
}

void
end_drawing()
{
    puts(INFO "End drawing");
}

void
deinit_graphics()
{
    puts(INFO "Deinit the graphics");
}

