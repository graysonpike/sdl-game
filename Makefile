main: main.o graphics.o world.o clock.o resources.o inputs.o fps_counter.o entity.o player.o hitbox.o crawler.o
	g++ -g -std=c++11 -o main.out main.o graphics.o world.o clock.o resources.o inputs.o entity.o player.o fps_counter.o hitbox.o crawler.o -lSDL2 -lSDL2_image -lSDL2_ttf

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

entity.o : game/entity.cpp
	g++ -g -c -std=c++11 game/entity.cpp

player.o : entities/player.cpp
	g++ -g -c -std=c++11 entities/player.cpp

crawler.o : entities/crawler.cpp
	g++ -g -c -std=c++11 entities/crawler.cpp

hitbox.o : game/hitbox.cpp
	g++ -g -c -std=c++11 game/hitbox.cpp
