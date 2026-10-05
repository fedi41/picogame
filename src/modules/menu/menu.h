#pragma once
#include <stdint.h>

struct categories_menu_state_t {
    int index;
    int count;
    const char **categories;
};

<<<<<<< HEAD
void update_categories_menu();
=======
extern const char *categories[];
extern struct categories_menu_state_t categories_menu_state;

>>>>>>> f13539a (fancy menu)

void draw_menu_bg();
void draw_categories_menu();
