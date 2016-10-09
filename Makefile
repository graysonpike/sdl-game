main: main.o sdl_boilerplate.o block.o linked_list.o
	gcc main.o sdl_boilerplate.o block.o linked_list.o -o main.out -lSDL2

main.o: main.c
	gcc main.c -c

sdl_boilerplate.o: graphics/sdl_boilerplate.c
	gcc graphics/sdl_boilerplate.c -c

block.o: game/block.c
	gcc game/block.c -c

linked_list.o: data_structure/linked_list.c
	gcc data_structure/linked_list.c -c