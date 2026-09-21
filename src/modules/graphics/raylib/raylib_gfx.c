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
end_drawing()
{
    EndDrawing();
}

void
clear_screen(color_t color)
{
    ClearBackground(RGB565_TO_COLOR(color));
}

void
deinit_graphics()
{
    return;
}
