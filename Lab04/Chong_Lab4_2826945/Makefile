Lab04: main.o Executive.o
	g++ -g -std=c++11 main.o Executive.o -o Lab04

main.o: main.cpp Executive.h
	g++ -g -std=c++11 -c main.cpp

Executive.o: Executive.h Executive.cpp BinaryNode.hpp BinaryNode.h BinarySearchTree.hpp BinarySearchTree.h
	g++ -g -std=c++11 -c Executive.cpp
	
clean:
	rm *.o Lab04

