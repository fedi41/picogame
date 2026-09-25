#include "lua_exec.h"
#include "lua/lua.h"
#include "lua/lauxlib.h"
#include "lua/lualib.h"
#include "modules/files/files.h"

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
}

int
lua_run(const char *pathname)
{
    int fd = file_open(pathname);
    LuaStream stream = {
        .fd = fd,
    };
    lua_State *L = luaL_newstate();
    if (!L) {
        return 69;
    }

    open_libs(L);

    // Compile the source code
    int status = lua_load(L, lua_reader, &stream, pathname, NULL);
    file_close(fd);
    if (status != LUA_OK) {
        const char *err = lua_tostring(L, -1);
        printf(ERROR "Lua: %s\n", err);
        lua_close(L);
        return 69;
    }
    // Execute the bytecode
    status = lua_pcall(L, 0, 0, 0);
    if (status != LUA_OK) {
        const char *err = lua_tostring(L, -1);
        printf(ERROR "Lua: %s\n", err);
        lua_close(L);
        return 69;
    }
    lua_close(L);
}
