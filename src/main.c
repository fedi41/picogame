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

    lua_State *L = lua_compile("test.lua");
    if (!L) {
        printf("Quit");
        return 69;
    }
    if (lua_init_engine(L) == 69) {
        return 69;
    }

    while(should_run()) {
        if (lua_update_engine(L) == 69) {
            break;
        }

        begin_drawing();

        lua_draw_engine(L);

        end_drawing();
    }

    lua_close(L);

    deinit_files();
    deinit_inputs();
    deinit_graphics();
    deinit_system();
    return 0;
}
