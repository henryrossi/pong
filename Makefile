app: ./src/main.cpp
	g++ ./src/main.cpp -o app -L/usr/local/Cellar/sfml/2.6.0/lib -lsfml-graphics -lsfml-window -lsfml-system
