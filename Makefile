main: main.o sdl_boilerplate.o game.o clock.o
	g++ -g -o main.out main.o sdl_boilerplate.o game.o clock.o  -lSDL2 -lSDL2_image -lSDL2_ttf

main.o: main.cpp
	g++ -g -c main.cpp

sdl_boilerplate.o: graphics/sdl_boilerplate.cpp
	g++ -g -c graphics/sdl_boilerplate.cpp

clock.o: game/clock.cpp
	g++ -g -c game/clock.cpp

game.o: game/game.cpp
	g++ -g -c game/game.cpp