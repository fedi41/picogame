#include "../files.h"
#include <emscripten.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
typedef struct {
    char **paths;
    uint16_t count;
} dirlist_t;
*/

EM_JS(char*, fetch_json_string_wasm, (const char* url_ptr), {
    return Asyncify.handleAsync(async () => {
        const url = UTF8ToString(url_ptr);
        const response = await fetch(url);
        const text = await response.text();

        const bytesLen = lengthBytesUTF8(text) + 1;
        const ptr = _malloc(bytesLen);
        stringToUTF8(text, ptr, bytesLen);
        return ptr;
    });
});

static dirlist_t 
parse_json_string_array(char* json)
{
    dirlist_t list = { NULL, 0 };
    if (!json) return list;

    int capacity = 10;
    list.paths = malloc(capacity * sizeof(char*));

    char* p = json;
    int in_string = 0;
    char buffer[256];
    int buf_idx = 0;

    while (*p != '\0') {
        if (*p == '"' && (p == json || *(p - 1) != '\\')) {
            in_string = !in_string;
            if (!in_string) {
                buffer[buf_idx] = '\0';
                if (list.count >= capacity) {
                    capacity *= 2;
                    list.paths = realloc(list.paths, capacity * sizeof(char*));
                }
                list.paths[list.count++] = strdup(buffer);
                buf_idx = 0;
            }
        } else if (in_string) {
            if (buf_idx < sizeof(buffer) - 1) {
                buffer[buf_idx++] = *p;
            }
        }
        p++;
    }

    return list;
}

dirlist_t
lsdir(const char* path)
{
    char buf[256];
    snprintf(buf, 256, "https://raw.githubusercontent.com/fedi41/picogame/refs/heads/main/%s/list.json", path);
    char* json_str = fetch_json_string_wasm(buf);
    dirlist_t list = parse_json_string_array(json_str);
    free(json_str);
    return list;
}

void
free_dirlist(dirlist_t *list)
{
    if (!list || !list->paths) return;
    for (int i = 0; i < list->count; i++) {
        free(list->paths[i]);
    }
    free(list->paths);
    list->paths = NULL;
    list->count = 0;
}

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

int
deinit_files()
{
    return 0;
}

