#ifndef LUA_INPUTS_H
#define LUA_INPUTS_H

#include "../lua/lua.h"
#include "../lua/lauxlib.h"
#include "../lua/lualib.h"

static int lua_is_btn_pressed(lua_State *L);
static int lua_is_btn_down(lua_State *L);
int luaopen_inputs(lua_State *L);

#endif
