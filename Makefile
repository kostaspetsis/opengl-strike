SRC=game.cpp\
    utils.cpp\
    Model.cpp\
    Globals.cpp\
    Scene.cpp\
    parsers/tinyXML/tinystr.cpp\
    parsers/tinyXML/tinyxml.cpp\
    parsers/tinyXML/tinyxmlerror.cpp\
    parsers/tinyXML/tinyxmlparser.cpp

make:$(SRC)
	g++ -pthread -Wall -std=c++17 -g $(SRC) -lglut -lGL -lGLU -o game 
clean:
	rm game
