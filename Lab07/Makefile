Lab07: main.o Executive.o
	g++ -g -std=c++11 main.o Executive.o -o Lab07

main.o: main.cpp Executive.h
	g++ -g -std=c++11 -c main.cpp

Executive.o: Executive.h Executive.cpp HeapInterface.h Max5_Heap.h Max5_Heap.hpp Min5_Heap.h Max5_Heap.hpp
	g++ -g -std=c++11 -c Executive.cpp
	
clean:
	rm *.o Lab07

