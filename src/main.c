#include "hal/hal.h"
#include <stdio.h>
#include <string.h>
#include "modules/graphics/graphics.h"
#include "modules/inputs/inputs.h"
#include "modules/files/files.h"

#include "lua/lua.h"
#include "lua/lauxlib.h"
#include "lua/lualib.h"

#define ERROR "ERROR: "

typedef struct {
    int fd;
    char buffer[255];
} LuaStream;

static const char
*lua_reader(lua_State *L, void *data, size_t *size)
{
    LuaStream *stream = (LuaStream *)data;
    ssize_t bytes_read = file_read(stream->buffer, 1, 255, stream->fd);
    if (bytes_read <= 0) {
        *size = 0;
        return NULL;
    }
    *size = (size_t) bytes_read;
    return stream->buffer;
}

int
main()
{
    init_system();
    init_graphics();
    init_inputs();
    init_files();

    int program = file_open("test.lua");
    printf("Program is %d\n", program);
    LuaStream stream = {
        .fd = program,
    };

    lua_State *L = luaL_newstate();
    if (L == NULL) { return 69; }

    luaL_requiref(L, "_G", luaopen_base, 1);
    lua_pop(L, 1);
    luaL_requiref(L, "math", luaopen_math, 1);
    lua_pop(L, 1);
    luaL_requiref(L, "string", luaopen_string, 1);
    lua_pop(L, 1);

    int status = lua_load(L, lua_reader, &stream, "test.lua", NULL);
    if (status != LUA_OK) {
        const char *err = lua_tostring(L, -1);
        printf(ERROR "Lua: %s\n", err);
        lua_pop(L, 1);
        lua_close(L);
        return 69;
    }
    // Execute bytecode
    status = lua_pcall(L, 0, 0, 0);
    if (status != LUA_OK) {
        const char *err = lua_tostring(L, -1);
        printf(ERROR "Lua: %s\n", err);
        lua_pop(L, 1);
        lua_close(L);
        return 69;
    }
    
    lua_close(L);

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
