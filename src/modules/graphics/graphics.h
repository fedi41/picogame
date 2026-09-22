#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <raylib.h>
#include <stdint.h>

typedef uint16_t color_t;

int init_graphics();
void begin_drawing();

void clear_screen(color_t color);
void draw_rect(int x, int y, int w, int h, color_t color);
void fill_rect(int x, int y, int w, int h, color_t color);
void draw_circle(int cx, int cy, int r, color_t color);
void fill_circle(int cx, int cy, int r, color_t color);
void draw_triangle(int x1, int y1, int x2, int y2, int x3, int y3, color_t color);
void fill_triangle(int x1, int y1, int x2, int y2, int x3, int y3, color_t color);

void end_drawing();
void deinit_graphics();

#endif
