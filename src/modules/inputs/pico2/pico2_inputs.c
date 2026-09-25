#include "../inputs.h"
#include <stdio.h>

// That's for later (buttons pins numbers)
#define PIN_A
#define PIN_B
#define PIN_X
#define PIN_Y
#define PIN_UP
#define PIN_DOWN
#define PIN_LEFT
#define PIN_RIGHT

#define INFO "INFO: "
#define WARNING "WARNING: "
#define ERROR "ERROR: "

int
init_inputs()
{
    puts(INFO "Inputs init");
    return 0;
}

int
is_btn_pressed(int btn)
{
    return 0;
}

int
is_btn_down(int btn)
{
    return 0;
}

int
deinit_inputs()
{
    return 0;
}
