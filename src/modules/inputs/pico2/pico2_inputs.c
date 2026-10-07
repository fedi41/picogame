#include "../inputs.h"
#include <stdio.h>
#include "hardware/gpio.h"

// That's for later (buttons pins numbers) 15, 17, 19, 21, 2, 18, 16, 20, 3
#define PIN_A 15 
#define PIN_B 17
#define PIN_X 19
#define PIN_Y 21
#define PIN_UP 2
#define PIN_DOWN 18
#define PIN_LEFT 16
#define PIN_RIGHT 20

const int allPins[8] = {PIN_A, PIN_B, PIN_X, PIN_Y, PIN_UP, PIN_DOWN, PIN_LEFT, PIN_RIGHT};

#define INFO "INFO: "
#define WARNING "WARNING: "
#define ERROR "ERROR: "

int
init_inputs()
{
    puts(INFO "Inputs init");         
    
    for (int i = 0; i < 8; i++) {
        gpio_init(allPins[i]);
        gpio_set_dir(allPins[i], GPIO_IN);
        gpio_pull_up(allPins[i]);
    }
 
    return 0;
}

int
is_btn_pressed(int btn)
{
    return is_btn_down(btn); // only as a test, change later
}

int
is_btn_down(int btn)
{
    switch (btn) {
    case BTN_DOWN:
        return gpio_get(PIN_DOWN) == 0;
    case BTN_UP:
        return gpio_get(PIN_UP) == 0;
    case BTN_LEFT:
        return gpio_get(PIN_LEFT) == 0;
    case BTN_RIGHT:
        return gpio_get(PIN_RIGHT) == 0;
    case BTN_A:
        return gpio_get(PIN_A) == 0;
    case BTN_B:
        return gpio_get(PIN_B) == 0;
    case BTN_X:
        return gpio_get(PIN_X) == 0;
    case BTN_Y:
        return gpio_get(PIN_Y) == 0;
    default:
        return 0;
    }
}

int
deinit_inputs()
{
    return 0;
}
