pong: main.o Paddle.o Ball.o Score.o
	g++ -o pong main.o Paddle.o Ball.o Score.o -L/usr/local/Cellar/sfml/2.6.0/lib -lsfml-graphics -lsfml-window -lsfml-system

Score.o: ./src/Score.cpp ./src/Score.hpp
	g++ -c -Wall ./src/Score.cpp

Ball.o: ./src/Ball.cpp ./src/Ball.hpp
	g++ -c -Wall ./src/Ball.cpp

Paddle.o: ./src/Paddle.cpp ./src/Paddle.hpp
	g++ -c -Wall ./src/Paddle.cpp

main.o: ./src/main.cpp ./src/Paddle.hpp 
	g++  -c -Wall ./src/main.cpp
