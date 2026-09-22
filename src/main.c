#include "hal/hal.h"
#include "modules/graphics/graphics.h"
#include "modules/inputs/inputs.h"

int
main()
{
    init_system();
    init_graphics();
    init_inputs();
    int x = 0;
    int y = 0;
    int speed = 5;
    while(should_run()) {
        if (is_btn_down(BTN_DOWN)) {
            y += speed;
        }
        if (is_btn_down(BTN_UP)) {
            y -= speed;
        }
        if (is_btn_down(BTN_LEFT)) {
            x -= speed;
        }
        if (is_btn_down(BTN_RIGHT)) {
            x += speed;
        }
 
        begin_drawing();
        clear_screen(0x0000);
        fill_circle(x, y, 5, 0xFF00);
        fill_triangle(x+10, y+10, x+30, y+10, x+25, y-15, 0xD0DA);
        end_drawing();
    }
    deinit_inputs();
    deinit_graphics();
    deinit_system();
    return 0;
}
