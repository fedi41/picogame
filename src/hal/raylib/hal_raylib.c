#include <raylib.h>
#include "../hal.h"

#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif


int
init_system()
{
    InitWindow(480, 480, "PicoGame");
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
