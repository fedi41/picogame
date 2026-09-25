#ifndef FILES_H
#define FILES_H

int init_files();
int file_open(const char *pathname);
size_t file_read(void *ptr, size_t size, size_t nb_elements, int fd); 
size_t file_write(void *ptr, size_t size, size_t nb_elements, int fd); 
void file_close(int fd);
int deinit_files();

#endif
