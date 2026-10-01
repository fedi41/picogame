#pragma once
#include <stdint.h>
#include <string.h>

typedef uint16_t color_t;

void init_text();
void draw_char(const char ascii, int x, int y, int scale, color_t color);
void draw_string(const char *text, int x, int y, int scale, color_t color);
size_t width_string(const char *text, int scale);
void draw_string_centered_x(const char *text, int x, int y, int scale, color_t color);
void draw_string_centered_xy(const char *text, int x, int y, int scale, color_t color);
