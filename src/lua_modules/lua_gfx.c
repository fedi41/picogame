#include "lua_gfx.h"

static const struct luaL_Reg graphics_lib[] = {
    {"fill_rect",    lua_fill_rect},
    {"clear_screen", lua_clear_screen},
    {NULL, NULL}  
};

static int
lua_fill_rect(lua_State *L)
{
    int x = (int)luaL_checkinteger(L, 1);
    int y = (int)luaL_checkinteger(L, 2);
    int w = (int)luaL_checkinteger(L, 3);
    int h = (int)luaL_checkinteger(L, 4);
    uint16_t color = (int)luaL_checkinteger(L, 5);
    fill_rect(x, y, w, h, color);
    return 0;
}

static int
lua_clear_screen(lua_State *L)
{
    uint16_t color = luaL_checkinteger(L, 1);
    clear_screen(color);
    return 0;
}

int
luaopen_graphics(lua_State *L)
{
    luaL_newlib(L, graphics_lib);
    return 1;
}
