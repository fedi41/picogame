#include "../graphics.h"
#include <stdio.h>
#include "pico/stdlib.h"
#include "LCD_1in3.h"
#include "GUI_Paint.h"

#define INFO "INFO: "

typedef uint16_t color_t;

UDOUBLE Imagesize = LCD_1IN3_HEIGHT*LCD_1IN3_WIDTH*2;
UWORD *BlackImage;

int
init_graphics()
{
    if(DEV_Module_Init()!=0){
        return -1;
    }
    DEV_SET_PWM(50);
    LCD_1IN3_Init(HORIZONTAL);
    if((BlackImage = (UWORD *)malloc(Imagesize)) == NULL) {
        printf("Failed to apply for black memory...\r\n");
        exit(0);
    }
    Paint_NewImage((UBYTE *)BlackImage,LCD_1IN3.WIDTH,LCD_1IN3.HEIGHT, 0, WHITE);
    Paint_SetScale(65);
    Paint_Clear(WHITE);
    Paint_SetRotate(ROTATE_0);
    Paint_Clear(WHITE);
    return 0;
}

void
begin_drawing()
{
    puts(INFO "Begin drawing");
    // no further work required here
}

void
clear_screen(color_t color)
{
    Paint_Clear(color);
    puts(INFO "Clear screen");
}

void
draw_rect(int x, int y, int w, int h, color_t color)
{
    Paint_DrawRectangle(x, y, x+w, y+h, color, DOT_PIXEL_1X1, DRAW_FILL_EMPTY);
    puts(INFO "Draw a rectangle");
}

void
fill_rect(int x, int y, int w, int h, color_t color)
{
    Paint_DrawRectangle(x, y, w, h, color,DOT_PIXEL_1X1, DRAW_FILL_FULL);
    puts(INFO "Fill a rectangle");
}

void
draw_circle(int cx, int cy, int r, color_t color)
{
    // TODO: make it draw a circle
    puts(INFO "Draw a circle");
}

void
fill_circle(int cx, int cy, int r, color_t color)
{
    //LCD_1IN3_DisplayPoint(cx, cy, color);
    puts(INFO "Fill a circle");
}

void
draw_triangle(int x1, int y1, int x2, int y2, int x3, int y3, color_t color)
{
    // TODO: make it draw a triangle
    puts(INFO "Draw a triangle");
}

void
fill_triangle(int x1, int y1, int x2, int y2, int x3, int y3, color_t color)
{
    // TODO: make it fill a triangle
    puts(INFO "Fill a triangle");
}

void
end_drawing()
{
    puts(INFO "End drawing");
    LCD_1IN3_Display(BlackImage);
}

void
deinit_graphics()
{
    puts(INFO "Deinit the graphics");
}
