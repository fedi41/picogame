#include <raylib.h>
#include "../graphics.h"

#define RGB565_TO_COLOR(c) (Color){ \
    .r = (unsigned char)((((uint16_t)(c) >> 11) & 0x1F) * 255 / 31), \
    .g = (unsigned char)((((uint16_t)(c) >> 5)  & 0x3F) * 255 / 63), \
    .b = (unsigned char)(( (uint16_t)(c)        & 0x1F) * 255 / 31), \
    .a = 255 \
}

int
init_graphics()
{
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
    DrawRectangleLines(w, y, w, h, RGB565_TO_COLOR(color));
}

void
fill_rect(int x, int y, int w, int h, color_t color)
{
    DrawRectangle(x, y, w, h, RGB565_TO_COLOR(color));
}

void
draw_circle(int cx, int cy, int r, color_t color)
{
    DrawCircleLines(cx, cy, r, RGB565_TO_COLOR(color));
}

void
fill_circle(int cx, int cy, int r, color_t color)
{
    DrawCircle(cx, cy, r, RGB565_TO_COLOR(color));
}

void
draw_triangle(int x1, int y1, int x2, int y2, int x3, int y3, color_t color) {
    DrawTriangleLines((Vector2){ x1, y1 },
                      (Vector2){ x2, y2 },
                      (Vector2){ x3, y3 }, RGB565_TO_COLOR(color));
}

void
fill_triangle(int x1, int y1, int x2, int y2, int x3, int y3, color_t color) {
    DrawTriangle((Vector2){ x1, y1 },
                 (Vector2){ x2, y2 },
                 (Vector2){ x3, y3 }, RGB565_TO_COLOR(color));
}



void
end_drawing()
{
    EndDrawing();
}

void
deinit_graphics()
{
    return;
}
