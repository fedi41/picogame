main:
	gcc -o main src/main.c src/hal/raylib/hal_raylib.c src/modules/graphics/raylib/raylib_gfx.c src/modules/inputs/raylib/raylib_inputs.c -lraylib -lm -lGL

run: main
	./main

clean: main
	rm main
