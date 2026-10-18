#pragma once
#include <stdint.h>

typedef struct {
    int index;
    int count;
    const char **categories;
    float anim_progress;
    int anim_direction;
    float anim_duration;
} categories_menu_state_t;

//extern const char *categories[];
//extern struct categories_menu_state_t categories_menu_state;

void draw_menu_bg();
void update_menu_bg(float dt);
void draw_categories_menu();
void update_categories_menu(float dt, int *state);
void draw_games_menu();
void update_games_menu(float dt, int *state);
