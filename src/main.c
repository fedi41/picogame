#include "hal/hal.h"
#include "modules/graphics/graphics.h"

int
main()
{
    init_system();
    init_graphics();
    while(should_run()) {
        begin_drawing();
        clear_screen(0xF000);
        end_drawing();
    }
    deinit_graphics();
    deinit_system();
    return 0;
}
