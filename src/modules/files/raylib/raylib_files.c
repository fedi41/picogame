#include <stdio.h>
#include "../files.h"

#define MAX_FILES 40 
#define INFO "INFO: "
#define WARNING "WARNING: "
#define ERROR "ERROR: "

FILE *fd_table[40];
int index_table;

int
init_files()
{
    index_table = 0;
    memset(fd_table, NULL, MAX_FILES);
    return 0;
}

int
file_open(const char *pathname)
{
    FILE *fd = fopen(pathname, "rwb");
    if (fd == NULL) {
        printf(ERROR "Failed to open the file '%s'\n", pathname);
        return -1;
    }
    fd_table[index_table] = fd;
    return index_table++;
}

size_t
file_read(void *ptr, size_t size, size_t nb_elements, int fd)
{
    if (fd_table[fd] != NULL) {
        return fread(ptr, size, nb_elements, fd_table[fd]);
    }
    puts(WARNING "The program can't read from an inexistant file");
    return 0;
}

size_t
file_write(void *ptr, size_t size, size_t nb_elements, int fd)
{
    if (fd_table[fd] != NULL) {
        return fwrite(ptr, size, nb_elements, fd_table[fd]);
    }
    puts(WARNING "The program can't write in an inexistant file");
    return 0;
}

void
file_close(int fd)
{
    printf(INFO "Close the file [%d]\n", fd);
    if (fd_table[fd] != NULL) {
        fclose(fd_table[fd]);
    }
    fd_table[fd] = NULL;
}

int
deinit_files()
{
    for (int i = 0; i < MAX_FILES; i++) {
        if (fd_table[i] != NULL) {
            fclose(fd_table[i]);
        }
    }
    puts(INFO "Closed everyfile");
    return 0;
}
