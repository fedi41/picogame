#ifndef LUA_EXEC_H
#define LUA_EXEC_H

typedef struct {
    int fd;
    char buffer[255];
} LuaStream;

int lua_run(const char *pathname);

#endif 
