main: main.o sdl_boilerplate.o block.o linked_list.o game.o render.o clock.o character.o resources.o
	gcc main.o sdl_boilerplate.o block.o linked_list.o game.o render.o clock.o character.o resources.o -o main.out -lSDL2 -lSDL2_image -lSDL2_ttf -std=c99 -g

main.o: main.c
	gcc main.c -c -std=c99

sdl_boilerplate.o: graphics/sdl_boilerplate.c
	gcc graphics/sdl_boilerplate.c -c

block.o: entities/block.c
	gcc entities/block.c -c -std=c99

linked_list.o: data_structure/linked_list.c
	gcc data_structure/linked_list.c -c -std=c99

game.o: game/game.c
	gcc game/game.c -c -std=c99

render.o: graphics/render.c
	gcc graphics/render.c -c -std=c99

clock.o: game/clock.c
	gcc game/clock.c -c -std=c99

character.o: entities/character.c
	gcc entities/character.c -c -std=c99

resources.o: graphics/resources.c
	gcc graphics/resources.c -c -std=c99
