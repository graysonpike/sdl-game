clean:
	rm *.o

main: main.o graphics.o world.o clock.o resources.o inputs.o fps_counter.o entity.o player.o hitbox.o overlay.o font_renderer.o missile.o collision_manager.o particle.o ship_part.o laser.o
	g++ -g -std=c++11 -o main.out main.o graphics.o world.o clock.o resources.o inputs.o entity.o player.o fps_counter.o hitbox.o overlay.o font_renderer.o missile.o collision_manager.o particle.o ship_part.o laser.o -lSDL2 -lSDL2_image -lSDL2_ttf

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

player.o: entities/player.cpp
	g++ -g -c -std=c++11 entities/player.cpp

missile.o: entities/missile.cpp
	g++ -g -c -std=c++11 entities/missile.cpp

laser.o: entities/laser.cpp
	g++ -g -c -std=c++11 entities/laser.cpp

particle.o : entities/particle.cpp
	g++ -g -c -std=c++11 entities/particle.cpp

ship_part.o : entities/ship_part.cpp
	g++ -g -c -std=c++11 entities/ship_part.cpp

hitbox.o : game/hitbox.cpp
	g++ -g -c -std=c++11 game/hitbox.cpp

overlay.o: ui/overlay.cpp
	g++ -g -c -std=c++11 ui/overlay.cpp	

font_renderer.o: graphics/font_renderer.cpp
	g++ -g -c -std=c++11 graphics/font_renderer.cpp	

collision_manager.o: game/collision_manager.cpp
	g++ -g -c -std=c++11 game/collision_manager.cpp	