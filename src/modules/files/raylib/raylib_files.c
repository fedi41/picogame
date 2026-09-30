#include <stdio.h>
#include <raylib.h>
#include <string.h>
#include <stdlib.h>
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
    memset(fd_table, 0, MAX_FILES);
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

dirlist_t 
lsdir(const char *path)
{
    dirlist_t list = { NULL, 0 };

    FilePathList raylib_list = LoadDirectoryFiles(path);
    if (raylib_list.count > 0 && raylib_list.paths != NULL) {
        list.count = raylib_list.count;
        list.paths = malloc(list.count * sizeof(char *));

        
        for (unsigned int i = 0; i < list.count; i++) {
            const char *path = raylib_list.paths[i];
            const char *last_slash = strrchr(path, '/');
            const char *last_antislash = strrchr(path, '\\');

            const char *name = last_slash;
            if (last_antislash > name) {
                name = last_antislash;
            }

            if (name != NULL) {
                name++; 
            } else {
                name = path;
            }

            list.paths[i] = strdup(name);
        }
    }
    UnloadDirectoryFiles(raylib_list);
    return list;
}

void
free_dirlist(dirlist_t *list)
{
    if (list->paths) {
        for (unsigned int i = 0; i < list->count; i++) {
            free(list->paths[i]);
        }
        free(list->paths);
        list->paths = NULL;
    }
    list->count = 0;
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
