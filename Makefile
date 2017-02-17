main: main.o sdl_boilerplate.o game.o clock.o render.o resources.o
	g++ -g -std=c++11 -o main.out main.o sdl_boilerplate.o game.o clock.o render.o resources.o  -lSDL2 -lSDL2_image -lSDL2_ttf

main.o: main.cpp
	g++ -g -c -std=c++11 main.cpp

sdl_boilerplate.o: graphics/sdl_boilerplate.cpp
	g++ -g -c -std=c++11 graphics/sdl_boilerplate.cpp

clock.o: game/clock.cpp
	g++ -g -c -std=c++11 game/clock.cpp

game.o: game/game.cpp
	g++ -g -c -std=c++11 game/game.cpp

render.o: graphics/render.cpp
	g++ -g -c -std=c++11 graphics/render.cpp

resources.o: graphics/resources.cpp
	g++ -g -c -std=c++11 graphics/resources.cpp