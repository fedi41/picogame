#ifndef FILES_H
#define FILES_H

#include <stddef.h>
#include <stdint.h>

typedef struct {
    char **paths;
    uint16_t count;
} dirlist_t;

int init_files();
int file_open(const char *pathname);
size_t file_read(void *ptr, size_t size, size_t nb_elements, int fd); 
size_t file_write(void *ptr, size_t size, size_t nb_elements, int fd); 
void file_close(int fd);
dirlist_t lsdir(const char *path);
void free_dirlist(dirlist_t *list);
int deinit_files();

#endif
