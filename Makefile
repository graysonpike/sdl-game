main: main.o sdl_boilerplate.o
	gcc main.o sdl_boilerplate.o -o main.out -lSDL2

main.o: main.c
	gcc main.c -c

sdl_boilerplate.o: graphics/sdl_boilerplate.c
	gcc graphics/sdl_boilerplate.c -c