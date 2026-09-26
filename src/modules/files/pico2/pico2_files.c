#include "../files.h"

int
init_files()
{
    return 69;
}

int
file_open(const char *pathname)
{
    return 0;
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
{
    return;
}

int
deinit_files()
{
    return 69;
}
