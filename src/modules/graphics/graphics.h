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

void end_drawing();
void deinit_graphics();

#endif
