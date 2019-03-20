Lab08: main.o Executive.o
	g++ -g -std=c++11 main.o Executive.o -o Lab08

main.o: main.cpp Executive.h
	g++ -g -std=c++11 -c main.cpp

Executive.o: Executive.h Executive.cpp HeapInterface.h MaxMin_Heap.h MaxMin_Heap.hpp MinMax_Heap.h MinMax_Heap.hpp
	g++ -g -std=c++11 -c Executive.cpp
	
clean:
	rm *.o Lab08

