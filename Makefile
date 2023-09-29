PROG=moeunier
SRC_DIR = src/
SRC_FILES = src/*.cpp
OBJ = $(foreach file, $(SRC_FILES), $(file:.c=.o))

all: compile link

compile:
#	g++ -Isrc/include -c main.cpp
	g++ -std=c++17  -I"./libs/" -I"./libs/sfml/include" -c src/*.cpp

link:
#	g++ main.o -o main -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system
#	g++ $(OBJ) -o bin/$(PROG)  -I./includes/ -Llibs/lua/lib -llua54 -Llibs/sfml/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
	g++ $(OBJ) -o bin/$(PROG)  -I./includes/ -Llibs/lua/lib -llua54 -Llibs/sfml/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

run:
	.\bin\$(PROG).exe

clean:
	rm main.o
	rm .\bin\$(PROG).exe
	