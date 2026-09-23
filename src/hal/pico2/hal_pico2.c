#include "../hal.h"
#include <stdio.h>
#include "pico/stdlib.h"

int
init_system()
{
    //stdio_init_all();
    gpio_init(25);
    gpio_set_dir(25, GPIO_OUT);
    gpio_put(25, 1);
    printf("Hello World");
    return 0;
}

void
deinit_system()
{
    return;
}

int
should_run()
{
    return 1;
}
