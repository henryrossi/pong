pong: main.o PlayerBar.o Ball.o
	g++ -o pong main.o PlayerBar.o Ball.o -L/usr/local/Cellar/sfml/2.6.0/lib -lsfml-graphics -lsfml-window -lsfml-system

Ball.o: ./src/Ball.cpp ./src/Ball.hpp
	g++ -c -Wall ./src/Ball.cpp

PlayerBar.o: ./src/PlayerBar.cpp ./src/PlayerBar.hpp
	g++ -c -Wall ./src/PlayerBar.cpp

main.o: ./src/main.cpp ./src/PlayerBar.hpp 
	g++  -c -Wall ./src/main.cpp
