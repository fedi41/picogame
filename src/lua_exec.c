#include <stdint.h>
#include "lua_exec.h"
#include "lua/lua.h"
#include "lua/lauxlib.h"
#include "lua/lualib.h"
#include "lua_modules/lua_gfx.h"
#include "lua_modules/lua_inputs.h"
#include "modules/files/files.h"
#include "modules/graphics/graphics.h"
#include "hal/hal.h"

#define ERROR "ERROR: "

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

void
open_libs(lua_State *L)
{
    luaL_requiref(L, "_G", luaopen_base, 1);
    lua_pop(L, 1);
    luaL_requiref(L, "math", luaopen_math, 1);
    lua_pop(L, 1);
    luaL_requiref(L, "string", luaopen_string, 1);
    lua_pop(L, 1);
    luaL_requiref(L, "gfx", luaopen_graphics, 1);
    lua_pop(L, 1);
    luaL_requiref(L, "input", luaopen_inputs, 1);
    lua_pop(L, 1);
}

lua_State
*lua_compile(const char *pathname)
{
    int fd = file_open(pathname);
    LuaStream stream = {
        .fd = fd,
    };
    lua_State *L = luaL_newstate();
    if (!L) {
        return NULL;
    }

    open_libs(L);

    // Compile the source code
    int status = lua_load(L, lua_reader, &stream, pathname, NULL);
    file_close(fd);
    if (status != LUA_OK) {
        const char *err = lua_tostring(L, -1);
        printf(ERROR "Lua: %s\n", err);
        return NULL;
    }

    //lua_close(L);
    return L;
}

int
lua_init_engine(lua_State *L)
{
    // First we need to execute the bytecode entirely
    if (lua_pcall(L, 0, 0, 0) != LUA_OK) {
        const char *err = lua_tostring(L, -1);
        printf(ERROR "Lua: %s\n", err);
        lua_pop(L, 1);
        return 69;
    } 
    // Execute the init() function 
    lua_getglobal(L, "init");
    if (lua_isfunction(L, -1)) {
        int status = lua_pcall(L, 0, 0, 0);
        if (status != LUA_OK) {
            const char *err = lua_tostring(L, -1);
            printf(ERROR "Lua: %s\n", err);
            lua_pop(L, 1);
            return 69;
        }
    } else {
        lua_pop(L, 1);
    }
    return 0;
}

int
lua_update_engine(lua_State *L)
{
    // Execute the update() function
    lua_getglobal(L, "update");
    if (lua_isfunction(L, -1)) {
        int status = lua_pcall(L, 0, 0, 0);
        if (status != LUA_OK) {
            const char *err = lua_tostring(L, -1);
            printf(ERROR "Lua: %s\n", err);
            lua_pop(L, 1);
            return 69;
        }
    } else {
        lua_pop(L, 1);
    }
    return 0;
}

int
lua_draw_engine(lua_State *L)
{
    // Execute the draw() function
    lua_getglobal(L, "draw");
    if (lua_isfunction(L, -1)) {
        int status = lua_pcall(L, 0, 0, 0);
        if (status != LUA_OK) {
            const char *err = lua_tostring(L, -1);
            printf(ERROR "Lua: %s\n", err);
            lua_pop(L, 1);
            return 69;
        }
    } else {
        lua_pop(L, 1);
    }
    return 0;
}
