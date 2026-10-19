#include "../files.h"
#include <emscripten.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
init_files()
{
    return 0;
}

int
file_open(const char *pathname)
{
    return -1;
}

size_t
file_read(void *ptr, size_t size, size_t nb_elements, int fd)
{
    return 0;
}

size_t
file_write(void *ptr, size_t size, size_t nb_elements, int fd)
{
    return 0;
}

void
file_close(int fd)
{}

dirlist_t
lsdir(const char *path)
{}

void
free_dirlist(dirlist_t *list)
{}

int
deinit_files()
{
    return 0;
}

