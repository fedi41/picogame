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

#define TEST_GRID_SIZE 10   

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

    //init_inputs();
    while(should_run()) {
        begin_drawing();

        for (int x = 0; x < 240/TEST_GRID_SIZE+TEST_GRID_SIZE; x++) 
        {
            for (int y = 0; y < 240/TEST_GRID_SIZE+TEST_GRID_SIZE; y++)
            {
                if ((x+y)%2==0)
                {
                    fill_rect(x*TEST_GRID_SIZE, y*TEST_GRID_SIZE, TEST_GRID_SIZE, TEST_GRID_SIZE, 0x0000);
                } else {
                    fill_rect(x*TEST_GRID_SIZE, y*TEST_GRID_SIZE, TEST_GRID_SIZE, TEST_GRID_SIZE, 0x1111);
                }
            }
        }


        //draw_text("Picogame! (or PicoGame?)", 10, 10, 18, 0xEEEE);
        draw_string_centered_x("Test", 120, 20, 1, 0xF800);
        draw_string_centered_xy("Picogame", 120, 120, 3, 0xFF00);
        draw_char('A', 200, 200, 6, 0xf9f9);
        end_drawing();
    }

    //free_dirlist(&list);

    deinit_files();
    deinit_inputs();
    deinit_graphics();
    deinit_system();
    return 0;
}
