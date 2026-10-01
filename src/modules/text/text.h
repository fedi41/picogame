#pragma once
#include <stdint.h>

typedef uint16_t color_t;

void init_text();
void draw_char(const char ascii, int x, int y, int scale, color_t color);
void draw_string(const char *text, int x, int y, int scale, color_t color);

