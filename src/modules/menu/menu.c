#include "menu.h"
#include "modules/graphics/graphics.h"
#include "modules/text/text.h"

#define MENU_BG_SIZE 10

void
draw_menu_bg() {
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
draw_categories_menu() {
    draw_menu_bg();
    draw_string_centered_xy("Picogame", 120, 120, 3, 0xFF00);
}

