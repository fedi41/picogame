#include <stdio.h>
#include "hal/hal.h"
#include "modules/graphics/graphics.h"
#include "modules/inputs/inputs.h"
#include "modules/files/files.h"
#include "modules/text/text.h"
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
    init_text();
    init_files();
    dirlist_t list = lsdir("src/");

    for (unsigned int i = 0; i < list.count; i++) {
        printf("Files : %s\n", list.paths[i]);
    }

    //init_inputs();
    int x = 10;
    int y = 10;
    //int speed = 5;
    while(should_run()) {
        begin_drawing();
        //draw_text("Picogame! (or PicoGame?)", 10, 10, 18, 0xEEEE);
        draw_string("Test", 20, 20, 1, 0xF800);
        draw_string("Picogame", 160, 160, 3, 0xFF00);
        draw_char('A', 200, 200, 6, 0xf9f9);
        end_drawing();
    }

    free_dirlist(&list);

    deinit_files();
    deinit_inputs();
    deinit_graphics();
    deinit_system();
    return 0;
}
