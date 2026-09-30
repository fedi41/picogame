CC = emcc

SRC_DIRS = src \
           src/hal/raylib \
           src/modules/graphics/raylib \
           src/modules/inputs/raylib \
           src/modules/files/raylib \
           src/modules/text/raylib \
           src/modules/text/fonts \
           src/lua \
           src/lua_modules

SRCS = $(wildcard $(addsuffix /*.c, $(SRC_DIRS)))

INCLUDES = -Iinclude \
           -Isrc \
           -I/home/wilrakov/dev2026/vendored/raylib/src

CFLAGS = -DPLATFORM_WEB -Os -Wall -Wextra $(INCLUDES)

RAYLIB_LIB = /home/wilrakov/dev2026/vendored/raylib/src/libraylib.a
LDFLAGS = $(RAYLIB_LIB) \
          --shell-file web/shell_minimal.html \
          -s USE_GLFW=3 \
          -s WASM=1 \
          -s ALLOW_MEMORY_GROWTH=1 \
          -s FORCE_FILESYSTEM=1 \
          -s ASYNCIFY

OUT_DIR = build_web
TARGET = $(OUT_DIR)/index.html

all: $(TARGET)

$(TARGET):
	@mkdir -p $(OUT_DIR)
	$(CC) $(SRCS) $(CFLAGS) $(LDFLAGS) -o $(TARGET)

clean:
	rm -rf $(OUT_DIR)

.PHONY: all clean
