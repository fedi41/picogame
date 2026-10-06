#include <stdio.h>
#include "hal/hal.h"
#include "modules/graphics/graphics.h"
#include "modules/inputs/inputs.h"
#include "modules/files/files.h"
#include "modules/text/text.h"
#include "modules/menu/menu.h"
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
    //init_files();
    //dirlist_t list = lsdir("src/");

    //for (unsigned int i = 0; i < list.count; i++) {
    //    printf("Files : %s\n", list.paths[i]);
    //}
    float timer = 0.0f;

    //init_inputs();
    while(should_run()) {
        update_categories_menu();
        begin_drawing();

        draw_categories_menu();

        //draw_string_centered_x("Test", 120, 20, 1, 0xF800);
        //draw_string_centered_xy("Picogame", 120, 120, 3, 0xFF00);
        //draw_char('A', 200, 200, 6, 0xf9f9);
        float deltaTime = end_drawing();
    }

    //free_dirlist(&list);

    deinit_files();
    deinit_inputs();
    deinit_graphics();
    deinit_system();
    return 0;
}
