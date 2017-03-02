main: main.o graphics.o world.o clock.o resources.o inputs.o fps_counter.o
	g++ -g -std=c++11 -o main.out main.o graphics.o world.o clock.o resources.o inputs.o fps_counter.o -lSDL2 -lSDL2_image -lSDL2_ttf

main.o: main.cpp
	g++ -g -c -std=c++11 main.cpp

graphics.o: graphics/graphics.cpp
	g++ -g -c -std=c++11 graphics/graphics.cpp

world.o: game/world.cpp
	g++ -g -c -std=c++11 game/world.cpp

inputs.o: input/inputs.cpp
	g++ -g -c -std=c++11 input/inputs.cpp

clock.o: game/clock.cpp
	g++ -g -c -std=c++11 game/clock.cpp

game.o: game/game.cpp
	g++ -g -c -std=c++11 game/game.cpp

resources.o: graphics/resources.cpp
	g++ -g -c -std=c++11 graphics/resources.cpp

fps_counter.o : graphics/fps_counter.cpp
	g++ -g -c -std=c++11 graphics/fps_counter.cpp	