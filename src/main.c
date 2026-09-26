#include <stdio.h>
#include "hal/hal.h"
#include "modules/graphics/graphics.h"
#include "modules/inputs/inputs.h"
#include "modules/files/files.h"
#include "lua_exec.h"

#include "lua/lua.h"
#include "lua/lauxlib.h"
#include "lua/lualib.h"

int
main()
{
    init_system();
    init_graphics();
    init_inputs();
    init_files();

    //init_inputs();
    int x = 10;
    int y = 10;
    //int speed = 5;
    while(should_run()) {
        begin_drawing();
        clear_screen(0xFFFF);
        fill_circle(x, y, 5, 0xFFFF);
        fill_triangle(x+10, y+10, x+30, y+10, x+25, y-15, 0xD0DA);
        end_drawing();
    }

    deinit_files();
    deinit_inputs();
    deinit_graphics();
    deinit_system();
    return 0;
}
