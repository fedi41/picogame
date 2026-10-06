#pragma once
#include <stdint.h>

struct categories_menu_state_t {
    int index;
    int count;
    const char **categories;
};

extern const char *categories[];
extern struct categories_menu_state_t categories_menu_state;

void draw_menu_bg();
void draw_categories_menu();
