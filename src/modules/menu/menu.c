#include "menu.h"
#include <ctype.h>
#include <stdio.h>
#include "../graphics/graphics.h"
#include "../text/text.h"
#include "../inputs/inputs.h"
#include "../files/files.h"

#define MENU_BG_SIZE 10
#define CATEGORIES_NUMBER 3
#define PREFIX "games/"

int bg_offset_scaled = 0;
dirlist_t list;
int list_idx = 0;
static int top_index = 0;
const int max_visible = 5;

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

void
str_to_lower(char *dst, const char* src)
{
    while (*src) {
        *dst++ = tolower(*src++); 
    }
}

void update_categories_menu(float dt, int *state)
{
    if (is_btn_down(BTN_A)) {
        const char *folder = categories_menu_state.categories[categories_menu_state.index];

        char low_folder[32];
        memset(low_folder, 0, 32);
        str_to_lower(low_folder, folder);

        char buf[32];
        memset(buf, 0, 32);

        snprintf(buf, 32, PREFIX "%s/", low_folder);
        puts(buf);
        list = lsdir(buf);
        *state = 1;
    }
    update_menu_bg(dt);
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
    int bg_offset = bg_offset_scaled / 1000;

    for (int x = -1; x < 240/MENU_BG_SIZE+MENU_BG_SIZE; x++)
    {
        for (int y = -1; y < 240/MENU_BG_SIZE+MENU_BG_SIZE; y++)
        {
            if ((x+y)%2==0)
            {
                fill_rect(x*MENU_BG_SIZE+bg_offset, y*MENU_BG_SIZE+bg_offset, MENU_BG_SIZE, MENU_BG_SIZE, 0x1000);
            } else {
                fill_rect(x*MENU_BG_SIZE+bg_offset, y*MENU_BG_SIZE+bg_offset, MENU_BG_SIZE, MENU_BG_SIZE, 0x0001);
            }
        }
    }
}

void
update_menu_bg(float dt)
{
    bg_offset_scaled += dt*1000*20; 
    //bg_offset_scaled = (bg_offset_scaled/1000.0f) % MENU_BG_SIZE; 

    if (bg_offset_scaled >= MENU_BG_SIZE * 1000) bg_offset_scaled = 0;
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

void
update_games_menu(float dt, int *state)
{
    if (is_btn_down(BTN_B)) {
        free_dirlist(&list);
        *state = 0;
        return;
    }

    if (is_btn_down(BTN_A)) {
        free_dirlist(&list);
        *state = 2;
        return;
    }


    if (is_btn_pressed(BTN_DOWN)) {
        list_idx++;
        if (list_idx >= list.count) {
            list_idx = 0;
            top_index = 0;
        } else if (list_idx >= top_index + max_visible) {
            top_index = list_idx - max_visible + 1;
        }
    }
    if (is_btn_pressed(BTN_UP)) {
        list_idx--;
        if (list_idx < 0) {
            list_idx = list.count - 1;
            top_index = list.count - max_visible;
            if (top_index < 0) {
                top_index = 0;
            }
        } else if (list_idx < top_index) {
            top_index = list_idx;
        }
    }

    update_menu_bg(dt);
}

void
draw_games_menu()
{
    draw_menu_bg();
    char buf[16];
    snprintf(buf, 16, "%d/%d", list_idx+1, list.count);
    draw_string_centered_x(buf, 220, 220, 1, 0xff00);
    draw_string_centered_x(categories_menu_state.categories[categories_menu_state.index], 120, 10, 3, 0xff00);

    int rect_h = 26;
    int gap = 8;
    int start_y = 40;
    int start_x = 20;
    int rect_w = 200;

    // The list
    for (int i = 0; i < max_visible; i++) {
        int item_idx = top_index + i;
        if (item_idx >= list.count) {
            break;
        }

        int y = start_y + i * (rect_h + gap);
        color_t txt_color = 0xff00;
        color_t bg_color = 0xC618;

        if (item_idx == list_idx) {
            txt_color = 0x0909;
            bg_color = 0x1082;
        }

        int bg_y = 44 + 14 * i;
        fill_rect(start_x, y, rect_w, rect_h, bg_color);
        draw_string_centered_x(list.paths[item_idx], 120, y+5, 2, txt_color);

        if (item_idx == list_idx) {
            draw_rect(start_x, y, rect_w, rect_h, txt_color);
        }
    }
    // Scrollbar
    if (list.count > max_visible) {
        int sb_x = start_x + rect_w + 6;
        int sb_y = start_y;
        int sb_w = 4;
        int sb_h = (max_visible * (rect_h + gap)) - gap;

        fill_rect(sb_x, sb_y, sb_w, sb_h, 0x1082);

        int thumb_h = (sb_h * max_visible) / list.count;
        if (thumb_h < 6) thumb_h = 6;

        int max_top = list.count - max_visible;
        int thumb_y = sb_y;
        if (max_top > 0) {
            thumb_y = sb_y + ((sb_h - thumb_h) * top_index) / max_top;
        }

        fill_rect(sb_x, thumb_y, sb_w, thumb_h, 0xff00);
    }
} 

void get_chosen_game_path(char* buf) {
    snprintf(buf, 32, PREFIX "%s/%s", categories_menu_state.categories[categories_menu_state.index], list.paths[list_idx]);
}
