Lab02: main.o Executive.o
	g++ -g -std=c++11 main.o Executive.o -o Lab02

main.o: main.cpp Executive.h
	g++ -g -std=c++11 -c main.cpp

Executive.o: Executive.h Executive.cpp HashTable.h HashTable.hpp LinkedList.h LinkedList.hpp Node.h Node.hpp
	g++ -g -std=c++11 -c Executive.cpp

clean:
	rm *.o Lab02
