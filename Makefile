SRC=game.cpp\
    utils.cpp\
    Model.cpp

make:$(SRC)
	g++ -std=c++17 $(SRC) -o game -lGL -lGLU -lglut
clean:
	rm game