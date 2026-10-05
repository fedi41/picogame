#include "menu.h"
#include "../graphics/graphics.h"
#include "../text/text.h"
#include "../inputs/inputs.h"

#define MENU_BG_SIZE 10
#define CATEGORIES_NUMBER 3

const static char* cat_names[CATEGORIES_NUMBER] = {
    "FPS",
    "Adventure",
    "Platformer"
};
int cat_index = 0;

const char *categories[] = {
    "test1",
    "test2",
    "test3",
    "test4",
    "test5"
};

struct categories_menu_state_t categories_menu_state = {
    .index = 0,
    .count = 5,
    .categories = categories
};


void
update_categories_menu()
{
    if (is_btn_down(BTN_LEFT)) {
        cat_index--;
    }
    if (is_btn_down(BTN_RIGHT)) {
        cat_index++;
    }
    if (cat_index < 0) {
        cat_index = CATEGORIES_NUMBER - 1;
    }
    if (cat_index >= CATEGORIES_NUMBER) {
        cat_index = 0;
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

void
draw_categories_menu()
{
    draw_menu_bg();
<<<<<<< HEAD
    draw_string_centered_xy(cat_names[cat_index], 120, 120, 3, 0xFF00);
=======
    draw_string_centered_xy("Picogame", 120, 20, 3, 0xFF00);

    draw_rect(1, 90, 60, 60, 0xFF00);
    draw_string_centered_xy(categories_menu_state.categories[(categories_menu_state.index - 1 + categories_menu_state.count) % categories_menu_state.count], 30, 120, 1, 0xFF00);

    draw_rect(65, 65, 110, 110, 0xFF00);
    draw_string_centered_xy(categories_menu_state.categories[categories_menu_state.index], 120, 120, 2, 0xFF00);

    draw_rect(179, 90, 60, 60, 0xFF00);
    draw_string_centered_xy(categories_menu_state.categories[(categories_menu_state.index+1) % categories_menu_state.count], 210, 120, 1, 0xFF00);
>>>>>>> f13539a (fancy menu)
}
