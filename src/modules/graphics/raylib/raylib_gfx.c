#include <raylib.h>
#include <stdio.h>
#include "../graphics.h"

#define INFO "INFO: "
#define SCALE 2

#define RGB565_TO_COLOR(c) (Color){ \
    .r = (unsigned char)((((uint16_t)(c) >> 11) & 0x1F) * 255 / 31), \
    .g = (unsigned char)((((uint16_t)(c) >> 5)  & 0x3F) * 255 / 63), \
    .b = (unsigned char)(( (uint16_t)(c)        & 0x1F) * 255 / 31), \
    .a = 255 \
}

int
init_graphics()
{
    puts(INFO "Init graphics");
    return 0;
}

void
begin_drawing()
{
    BeginDrawing();
}

void
clear_screen(color_t color)
{
    ClearBackground(RGB565_TO_COLOR(color));
}

void
draw_rect(int x, int y, int w, int h, color_t color)
{
    DrawRectangleLines(x*SCALE, y*SCALE, w*SCALE, h*SCALE, RGB565_TO_COLOR(color));
}

void
fill_rect(int x, int y, int w, int h, color_t color)
{
    DrawRectangle(x*SCALE, y*SCALE, w*SCALE, h*SCALE, RGB565_TO_COLOR(color));
}

void
draw_circle(int cx, int cy, int r, color_t color)
{
    DrawCircleLines(cx*SCALE, cy*SCALE, r, RGB565_TO_COLOR(color));
}

void
fill_circle(int cx, int cy, int r, color_t color)
{
    DrawCircle(cx*SCALE, cy*SCALE, r*SCALE, RGB565_TO_COLOR(color));
}

void
draw_triangle(int x1, int y1, int x2, int y2, int x3, int y3, color_t color) {
    DrawTriangleLines((Vector2){ x1*SCALE, y1*SCALE },
                      (Vector2){ x2*SCALE, y2*SCALE },
                      (Vector2){ x3*SCALE, y3*SCALE }, RGB565_TO_COLOR(color));
}

void
fill_triangle(int x1, int y1, int x2, int y2, int x3, int y3, color_t color) {
    DrawTriangle((Vector2){ x1*SCALE, y1*SCALE },
                 (Vector2){ x2*SCALE, y2*SCALE },
                 (Vector2){ x3*SCALE, y3*SCALE }, RGB565_TO_COLOR(color));
}


void
draw_text(const char *text, int x, int y, int size, color_t color)
{
    DrawText(text, x*SCALE, y*SCALE, size*SCALE, RGB565_TO_COLOR(color));
}

int
get_width_text(const char *text, int size)
{
    return MeasureText(text, size*SCALE);
}

void
end_drawing()
{
    EndDrawing();
}

void
deinit_graphics()
{
    puts(INFO "Deinit graphics");
    return;
}
