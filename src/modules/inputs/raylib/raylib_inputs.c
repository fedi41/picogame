#include "../inputs.h"
#include <raylib.h>
#include <stdio.h>

#define INFO "INFO: "

int
init_inputs()
{
    puts(INFO "Init inputs");
    return 0;
}

int
is_btn_pressed(int btn)
{
    switch (btn) {
    case BTN_DOWN:
        return IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN);
    case BTN_UP:
        return IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP);
    case BTN_LEFT:
        return IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT);
    case BTN_RIGHT:
        return IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT);
    case BTN_A:
        return IsKeyPressed(KEY_H);
    case BTN_B:
        return IsKeyPressed(KEY_J);
    case BTN_X:
        return IsKeyPressed(KEY_K);
    case BTN_Y:
        return IsKeyPressed(KEY_L);
    default:
        return 0;
    }
}

int
is_btn_down(int btn)
{
    switch (btn) {
    case BTN_DOWN:
        return IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN);
    case BTN_UP:
        return IsKeyDown(KEY_W) || IsKeyDown(KEY_UP);
    case BTN_LEFT:
        return IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT);
    case BTN_RIGHT:
        return IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT);
    case BTN_A:
        return IsKeyDown(KEY_H);
    case BTN_B:
        return IsKeyDown(KEY_J);
    case BTN_X:
        return IsKeyDown(KEY_K);
    case BTN_Y:
        return IsKeyDown(KEY_L);
    default:
        return 0;
    }
}

int
deinit_inputs()
{
    puts(INFO "Deinit inputs");
    return 0;
}


