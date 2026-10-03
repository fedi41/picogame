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
    draw_string_centered_xy(cat_names[cat_index], 120, 120, 3, 0xFF00);
}
