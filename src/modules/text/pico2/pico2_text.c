#include "../text.h"
#include "../fonts/fonts.h"
#include <stdint.h>
#include "modules/graphics/pico2-lcd1in3/GUI_Paint.h"

FONT *font = &Font6x8;


void
init_text() {
    puts("init text");
    return;
}

void
draw_char(const char ascii, int x, int y, int scale, color_t color)
{
    int Page, Column;

    if (x > Paint.Width || y > Paint.Height)
    {
        //Debug("Paint_DrawChar Input exceeds the normal display range\r\n");
        return;
    }

    uint32_t Char_Offset = (uint8_t)ascii * font->Height *
    (font->Width / 8 + (font->Width % 8 ? 1 : 0));
    const unsigned char *ptr = &font->table[Char_Offset];

    for (Page = 0; Page < font->Height; Page++)
    {
        for (Column = 0; Column < font->Width; Column++)
        {

            // To determine whether the font background color and screen background color is consistent
            if (*ptr & (0x04 << (Column % 8)))
            {        
                for (int XDir_Num = 0; XDir_Num < scale; XDir_Num++)
                {
                    for (int YDir_Num = 0; YDir_Num < scale; YDir_Num++)
                    {
                        Paint_SetPixel(x + Column * scale + XDir_Num - 1, y + Page * scale + YDir_Num - 1, color);
                    }
                }
            }
            // One pixel is 8 bits
            if (Column % 8 == 7)
                ptr++;
        } // Write a line
        if (font->Width % 8 != 0)
            ptr++;
    } // Write all
}

void
draw_string(const char *text, int x, int y, int scale, color_t color)
{
    if (x > Paint.Width || y > Paint.Height)
    {
        return;
    }


    while (*text != '\0')
    {
        draw_char(*text, x, y, scale, color);

        text++;

        x += font->Width*scale;
    }
}
