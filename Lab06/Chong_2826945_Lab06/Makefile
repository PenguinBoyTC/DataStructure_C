Lab06: main.o Executive.o
	g++ -g -std=c++11 main.o Executive.o -o Lab06

main.o: main.cpp Executive.h
	g++ -g -std=c++11 -c main.cpp

Executive.o: Executive.h Executive.cpp Timer.cpp QuadraticProbing.h QuadraticProbing.hpp DoubleHashing.h DoubleHashing.hpp Bucket.h Bucket.hpp HashTable.h HashTable.hpp LinkedList.h LinkedList.hpp Node.h Node.hpp
	g++ -g -std=c++11 -c Executive.cpp

clean:
	rm *.o Lab06
