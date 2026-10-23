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
    int err = pico_open(pathname, LFS_O_RDWR);
    if (err > -1) return err; // no error (yay)
    printf(ERROR "failed to open file '%s'\n", pathname);
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
{
    return;
}

int
deinit_files()
{
    return 69;
}
