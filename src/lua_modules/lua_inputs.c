#include "lua_inputs.h"
#include "../modules/inputs/inputs.h"

static const struct luaL_Reg inputs_lib[] = {
    {"btn_pressed", lua_is_btn_pressed},
    {"btn_down", lua_is_btn_down},
    {NULL, NULL}
};

static int
lua_is_btn_pressed(lua_State *L)
{
    int btn = luaL_checkinteger(L, 1);
    if (is_btn_pressed(btn)) {
        lua_pushboolean(L, 1);
        return 1;
    }
    lua_pushboolean(L, 0);
    return 1;
}

static int
lua_is_btn_down(lua_State *L)
{
    int btn = luaL_checkinteger(L, 1);
    if (is_btn_down(btn)) {
        lua_pushboolean(L, 1);
        return 1;
    }
    lua_pushboolean(L, 0);
    return 1;
}

int
luaopen_inputs(lua_State *L)
{
    luaL_newlib(L, inputs_lib);
    return 1;
}
