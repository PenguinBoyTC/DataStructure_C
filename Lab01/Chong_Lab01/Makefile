Lab01: main.o Executive.o
	g++ -g -std=c++11 main.o Executive.o -o Lab01

main.o: main.cpp Executive.h
	g++ -g -std=c++11 -c main.cpp

Executive.o: Executive.h Executive.cpp LinkedList.h LinkedList.hpp Node.h Node.hpp
	g++ -g -std=c++11 -c Executive.cpp

clean:
	rm *.o Lab01
