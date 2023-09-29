PROG=moeunier
SRC_DIR = src/
SRC_FILES = main.cpp \
					Game.cpp

#SRC = $(foreach file, $(SRC_FILES), $(addprefix $(SRC_DIR), $(file)))
OBJ = $(foreach file, $(SRC_FILES), $(file:.cpp=.o))
#OBJ = $(SRC:.cpp=.o)

all: compile link

compile:
	g++ -std=c++17  -I"./libs/" -I"./libs/sfml/include" -c src/*.cpp

link:
#	g++ main.o -o main -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system
	g++ $(OBJ) -o bin/$(PROG)  -I./includes/ -Llibs/lua/lib -llua54 -Llibs/sfml/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

run:
	.\bin\$(PROG).exe

clean:
	rm $(OBJ)
	rm .\bin\$(PROG).exe
	