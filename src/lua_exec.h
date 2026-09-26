#ifndef LUA_EXEC_H
#define LUA_EXEC_H

#include "lua/lua.h"
#include "lua/lauxlib.h"
#include "lua/lualib.h"

typedef struct {
    int fd;
    char buffer[255];
} LuaStream;

lua_State *lua_compile(const char *pathname);
int lua_init_engine(lua_State *L);
int lua_update_engine(lua_State *L);
int lua_draw_engine(lua_State *L);

#endif 
