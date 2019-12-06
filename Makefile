SRC=game.cpp\
    utils.cpp\
    Model.cpp\
    Globals.cpp

make:$(SRC)
	g++ -pthread -Wall -std=c++17 -g $(SRC) -lglut -lGL -lGLU -o game 
clean:
	rm game
