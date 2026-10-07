#include "menu.h"
#include "../graphics/graphics.h"
#include "../text/text.h"
#include "../inputs/inputs.h"

#define MENU_BG_SIZE 10
#define CATEGORIES_NUMBER 3

typedef struct {
    float x, y, size;
} Slot;

static const Slot SLOTS[3] = {
    { 1.0f,   90.0f, 60.0f  },
    { 65.0f,  65.0f, 110.0f },
    { 179.0f, 90.0f, 60.0f  } 
};

const static char* cat_names[CATEGORIES_NUMBER] = {
    "FPS",
    "Adventure",
    "Platformer"
};

categories_menu_state_t categories_menu_state = {
    .index = 0,
    .count = CATEGORIES_NUMBER,
    .categories = cat_names,
    .anim_progress = 1.0f,
    .anim_direction = 0,
    .anim_duration = 0.20f
};

static inline float lerp(float a, float b, float t) {
    return a + t * (b - a);
}

void update_categories_menu(float dt)
{
    if (categories_menu_state.anim_direction != 0) {
        categories_menu_state.anim_progress += dt / categories_menu_state.anim_duration;

        if (categories_menu_state.anim_progress >= 1.0f) {
            categories_menu_state.anim_progress = 1.0f;
            categories_menu_state.index = (categories_menu_state.index + categories_menu_state.anim_direction + categories_menu_state.count) % categories_menu_state.count;
            categories_menu_state.anim_direction = 0;
        }
        return;
    }

    if (is_btn_down(BTN_LEFT)) {
        categories_menu_state.anim_direction = -1;
        categories_menu_state.anim_progress = 0.0f;
    } 
    else if (is_btn_down(BTN_RIGHT)) {
        categories_menu_state.anim_direction = 1;
        categories_menu_state.anim_progress = 0.0f;
    }
}

void
draw_menu_bg()
{
    for (int x = 0; x < 240/MENU_BG_SIZE+MENU_BG_SIZE; x++)
    {
        for (int y = 0; y < 240/MENU_BG_SIZE+MENU_BG_SIZE; y++)
        {
            if ((x+y)%2==0)
            {
                fill_rect(x*MENU_BG_SIZE, y*MENU_BG_SIZE, MENU_BG_SIZE, MENU_BG_SIZE, 0x1000);
            } else {
                fill_rect(x*MENU_BG_SIZE, y*MENU_BG_SIZE, MENU_BG_SIZE, MENU_BG_SIZE, 0x0001);
            }
        }
    }
}

void draw_categories_menu()
{
    draw_menu_bg();
    draw_string_centered_xy("Picogame", 120, 20, 3, 0xFF00);

    float t = categories_menu_state.anim_progress;
    int dir = categories_menu_state.anim_direction;
    int curr = categories_menu_state.index;

    int idx_left   = (curr - 1 + categories_menu_state.count) % categories_menu_state.count;
    int idx_center = curr;
    int idx_right  = (curr + 1) % categories_menu_state.count;

    Slot pos_left, pos_center, pos_right;

    if (dir == 0) {
        pos_left   = SLOTS[0];
        pos_center = SLOTS[1];
        pos_right  = SLOTS[2];
    } else if (dir == 1) {
        pos_left.x    = lerp(SLOTS[0].x, -60.0f, t);
        pos_left.y    = lerp(SLOTS[0].y, 90.0f, t);
        pos_left.size = lerp(SLOTS[0].size, 60.0f, t);

        pos_center.x    = lerp(SLOTS[1].x, SLOTS[0].x, t);
        pos_center.y    = lerp(SLOTS[1].y, SLOTS[0].y, t);
        pos_center.size = lerp(SLOTS[1].size, SLOTS[0].size, t);

        pos_right.x    = lerp(SLOTS[2].x, SLOTS[1].x, t);
        pos_right.y    = lerp(SLOTS[2].y, SLOTS[1].y, t);
        pos_right.size = lerp(SLOTS[2].size, SLOTS[1].size, t);
    } else {
        pos_left.x    = lerp(SLOTS[0].x, SLOTS[1].x, t);
        pos_left.y    = lerp(SLOTS[0].y, SLOTS[1].y, t);
        pos_left.size = lerp(SLOTS[0].size, SLOTS[1].size, t);

        pos_center.x    = lerp(SLOTS[1].x, SLOTS[2].x, t);
        pos_center.y    = lerp(SLOTS[1].y, SLOTS[2].y, t);
        pos_center.size = lerp(SLOTS[1].size, SLOTS[2].size, t);

        pos_right.x    = lerp(SLOTS[2].x, 240.0f, t);
        pos_right.y    = lerp(SLOTS[2].y, 90.0f, t);
        pos_right.size = lerp(SLOTS[2].size, 60.0f, t);
    }

    draw_rect((int)pos_left.x, (int)pos_left.y, (int)pos_left.size, (int)pos_left.size, 0xFF00);
    draw_string_centered_xy(categories_menu_state.categories[idx_left], (int)(pos_left.x + pos_left.size / 2.0f), (int)(pos_left.y + pos_left.size / 2.0f), 1, 0xFF00);

    draw_rect((int)pos_right.x, (int)pos_right.y, (int)pos_right.size, (int)pos_right.size, 0xFF00);
    draw_string_centered_xy(categories_menu_state.categories[idx_right], (int)(pos_right.x + pos_right.size / 2.0f), (int)(pos_right.y + pos_right.size / 2.0f), 1, 0xFF00);

    draw_rect((int)pos_center.x, (int)pos_center.y, (int)pos_center.size, (int)pos_center.size, 0xFF00);
    draw_string_centered_xy(categories_menu_state.categories[idx_center], (int)(pos_center.x + pos_center.size / 2.0f), (int)(pos_center.y + pos_center.size / 2.0f), 1, 0xFF00);
    //draw_string_centered_xy(categories_menu_state.categories[idx_center], (int)(pos_center.x + pos_center.size / 2.0f), (int)(pos_center.y + pos_center.size / 2.0f), (dir == 0) ? 2 : 1, 0xFF00);
}
