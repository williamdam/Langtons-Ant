main: main.o validate.o Ant.o
	g++ -std=c++0x main.o validate.o Ant.o -o main

main.o: main.cpp
	g++ -std=c++0x -c main.cpp

Ant.o: Ant.cpp Ant.hpp
	g++ -std=c++0x -c Ant.cpp

validate.o: validate.cpp validate.hpp
	g++ -std=c++0x -c validate.cpp

clean:
	rm *.o main
