#include "hal/hal.h"
#include <stdio.h>
#include "modules/graphics/graphics.h"
#include "modules/inputs/inputs.h"
#include "modules/files/files.h"

int
main()
{
    init_system();
    init_graphics();
    init_inputs();
    init_files();
    int program = file_open("test.lua");
    printf("Program is %d\n", program);
    char buffer[255];
    memset(buffer, 0, 255);
    file_read(buffer, 1, 255,program);
    printf("%s\n", buffer);
    while(should_run()) {
        begin_drawing();
        clear_screen(0x0000);
        end_drawing();
    }
    file_close(program);
    deinit_files();
    deinit_inputs();
    deinit_graphics();
    deinit_system();
    return 0;
}
