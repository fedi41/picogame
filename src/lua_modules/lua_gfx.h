#ifndef LUA_GFX_H
#define LUA_GFX_H

#include <stdint.h>
#include "../lua/lua.h"
#include "../lua/lauxlib.h"
#include "../lua/lualib.h"
#include "../modules/graphics/graphics.h"

static int lua_fill_rect(lua_State *L);
static int lua_clear_screen(lua_State *L);
int luaopen_graphics(lua_State *L);

#endif
