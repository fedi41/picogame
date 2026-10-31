#include "../files.h"
#include "pico_lfs.h"

#define FS_SIZE (256 * 1024)

#ifdef PICO_CYW43_SUPPORTED
  #include "pico/btstack_flash_bank.h"
  #define FLASH_OFFSET (PICO_FLASH_BANK_STORAGE_OFFSET - FS_SIZE)
#else
  #define FLASH_OFFSET (PICO_FLASH_SIZE_BYTES - FS_SIZE)
#endif

#define INFO "INFO: "
#define WARNING "WARNING: "
#define ERROR "ERROR: "

static struct lfs_config *lfs_cfg;
static lfs_t lfs;


int
init_files()
{
    lfs_cfg = pico_lfs_init(FLASH_OFFSET, FS_SIZE);
    if (!lfs_cfg) { printf(ERROR "out of memory"); return -1; }
  
    int err = lfs_mount(&lfs, lfs_cfg);
  
    if (err != LFS_ERR_OK) {
        /* Initialize new filesystem */
        err = lfs_format(&lfs, lfs_cfg);
        if (err != LFS_ERR_OK) { printf(ERROR "failed to format filesystem"); return -1; }
        err = lfs_mount(&lfs, lfs_cfg);
        if (err != LFS_ERR_OK) { printf(ERROR "failed to mount new filesystem"); return -1; }
    }

    return 0;
}

int
file_open(const char *pathname)
{
    int fd = pico_open(pathname, LFS_O_RDWR);
    if (fd > -1) return fd; // return file id
    printf(ERROR "failed to open file '%s'\n", pathname);
    printf(ERROR " - '%s'", pico_errmsg(fd));
    return -1;
}

size_t
file_read(void *ptr, size_t size, size_t nb_elements, int fd) 
{
    if (size == 0 || nb_elements == 0)
        return 0;

    return pico_read(fd, ptr, size * nb_elements) / size;
}

size_t
file_write(void *ptr, size_t size, size_t nb_elements, int fd)
{
    if (size == 0 || nb_elements == 0)
        return 0;
    
    return pico_write(fd, ptr, size * nb_elements) / size;
}
void
file_close(int fd)
{
    return pico_close(fd);
}

dirlist_t
lsdir(const char *path) {

}

void
free_dirlist(dirlist_t *list) {

}

int
deinit_files()
{
    return 69;
}
