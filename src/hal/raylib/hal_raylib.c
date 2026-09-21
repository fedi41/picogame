#include <raylib.h>
#include "../hal.h"


int
init_system()
{
    InitWindow(320, 240, "PicoGame");
    SetTargetFPS(60);
    return 0;
}

void
deinit_system()
{
    CloseWindow();
}

int
should_run()
{
    return !WindowShouldClose();
}
