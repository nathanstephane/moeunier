PROG=moeunier

all: compile link

compile:
#	g++ -Isrc/include -c main.cpp
	g++ -std=c++17 -I"./libs/" -Ilibs/sfml/include -c src/*.cpp

link:
#	g++ main.o -o main -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system
	g++ main.o -o bin/$(PROG) -Llibs/lua/lib -llua54 -Llibs/sfml/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

run:
	.\bin\$(PROG).exe

clean:
	rm .\bin\$(PROG).exe
	