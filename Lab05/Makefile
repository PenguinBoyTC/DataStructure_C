Lab04: main.o Executive.o
	g++ -g -std=c++11 main.o Executive.o -o Lab05

main.o: main.cpp Executive.h
	g++ -g -std=c++11 -c main.cpp

Executive.o: Executive.h Executive.cpp twothree_Node.hpp twothree_Node.h twothree_tree.hpp twothree_tree.h
	g++ -g -std=c++11 -c Executive.cpp
	
clean:
	rm *.o Lab05

