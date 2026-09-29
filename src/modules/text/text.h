#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <stdint.h>

typedef uint16_t color_t;

void draw_char(int x, int y, const char ascii, color_t color, int scale);
void draw_string(int x, int y, const char *text, color_t color, int scale);

#endif
