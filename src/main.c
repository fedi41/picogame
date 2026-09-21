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
        clear_screen(0xF000);
        fill_rect(x, y, 10, 10, 0xFF00);
        end_drawing();
    }
    deinit_inputs();
    deinit_graphics();
    deinit_system();
    return 0;
}
