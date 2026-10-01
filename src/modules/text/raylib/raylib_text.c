#include "../text.h"
#include <raylib.h>
#include <stdint.h>
#include <string.h>
#include "../fonts/fonts.h"

#define SCALE 2

#define RGB565_TO_COLOR(c) (Color){ \
    .r = (unsigned char)((((uint16_t)(c) >> 11) & 0x1F) * 255 / 31), \
    .g = (unsigned char)((((uint16_t)(c) >> 5)  & 0x3F) * 255 / 63), \
    .b = (unsigned char)(( (uint16_t)(c)        & 0x1F) * 255 / 31), \
    .a = 255 \
}

Texture2D fontTexture;
FONT ft;

void
init_text()
{
    ft = Font6x8;
    int cw = ft.Width;
    int ch = ft.Height;
    int aw = 16 * cw;
    int ah = 16 * ch;
    Image fontImage = GenImageColor(aw, ah, BLANK);

    for (int i = 0; i < 256; i++) {
        int cx = (i % 16) * cw;
        int cy = (i / 16) * ch;

        for (int y = 0; y < ch; y++) {
            uint8_t row = (uint8_t) ft.table[i * ch + y];

            for (int x = 0; x < cw; x++) {
                if (row & (0x04 << x)) {
                    ImageDrawPixel(&fontImage, cx + x, cy + y, WHITE);
                }
            }
        }
    }
    fontTexture = LoadTextureFromImage(fontImage);
    UnloadImage(fontImage);
    SetTextureFilter(fontTexture, TEXTURE_FILTER_POINT);
}

void
draw_char(const char ascii, int x, int y, int scale, color_t color)
{
    int cw = ft.Width;
    int ch = ft.Height;

    unsigned char uc = (unsigned char)ascii;

    Rectangle srcRec = {
        (float)((uc % 16) * cw),
        (float)((uc / 16) * ch),
        (float)cw,
        (float)ch
    };

    Rectangle destRec = {
        (float)x * SCALE,
        (float)y * SCALE,
        (float)(cw * scale * SCALE),
        (float)(ch * scale * SCALE)
    };

    Vector2 origin = { 0.0f, 0.0f };

    DrawTexturePro(fontTexture, srcRec, destRec, origin, 0.0f, RGB565_TO_COLOR(color));
}

void
draw_string(const char *text, int x, int y, int scale, color_t color)
{
    int cw = ft.Width;
    int ch = ft.Height;

    for (int i = 0; text[i] != '\0'; i++) {
        unsigned char c = (unsigned char)text[i];

        Rectangle srcRec = {
            (float)((c % 16) * cw),
            (float)((c / 16) * ch),
            (float)cw,
            (float)ch
        };

        Rectangle destRec = {
            (float)x * SCALE,
            (float)y * SCALE,
            (float)(cw * scale * SCALE),
            (float)(ch * scale * SCALE)
        };

        Vector2 origin = { 0.0f, 0.0f };
        DrawTexturePro(fontTexture, srcRec, destRec, origin, 0.0f, RGB565_TO_COLOR(color));

        x += cw * scale;
    }
}

size_t
width_string(const char *text, int scale) {
    return strlen(text) * scale * ft.Width ;
}
void
draw_string_centered_x(const char *text, int x, int y, int scale, color_t color) {
    draw_string(text, x - width_string(text, scale)/2, y, scale, color);
}

void
draw_string_centered_xy(const char *text, int x, int y, int scale, color_t color) {
    draw_string(text, x - width_string(text, scale)/2, y - ft.Height/2*scale, scale, color);
}
